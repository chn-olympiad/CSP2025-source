#include<bits/stdc++.h> 
using namespace std;
int DFS(int n,vector<int> numbers,int need,int sum,bool add,int level){
	if(n==0){
		bool adding=add and level>=2;
		if(adding){
			return 1;
		}
	}else{
		int sums=0;
		bool flag=false;
		for(int i=n-1;i>=0;i--){
			bool adding=(sum+numbers[i]>need or add) and level>=2;
			if(adding){
				flag=true;
			}
			sums+=DFS(i,numbers,need,sum+numbers[i],adding,level+1);
		}
		if(flag){
			sums+=1;
		}
		return sums;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n=0;
	cin>>n;
	if(n<3){
		cout<<0<<endl;
		return 0;
	}
	vector<int> numbers(n,0);
	for(int i=0;i<n;i++){
		cin>>numbers[i];
	}
	sort(numbers.begin(),numbers.end());
	cout<<DFS(numbers.size()-1,numbers,numbers[numbers.size()-1],0,false,0)<<endl;
}
