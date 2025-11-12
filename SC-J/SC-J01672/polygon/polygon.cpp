#include<iostream>
#include<string>
#include<vector>
using namespace std;
int n;
void abc(int num,vector<int> a,int count,vector<int> &allt){
	vector<int> a1=a;
	while(true){
		
		for(int i=0;i<n;i++){
			allt.push_back(a[i]);
			abc(num,a1,count+1,allt);
		}
		if(count==num)return;
	}
	return;
}

int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int result=0;
    vector<int> a;
    vector<int> all;
    cin>>n;
    for(int i=0;i<n;i++){
    	int tmp;
    	cin>>tmp;
    	a.push_back(tmp);
	}
	for(int i=3;i<=n;i++){
		for(int j=0;j<n;i++){
			vector<int> allt=all;
			vector<int> a1=a;
			allt.push_back(j);
			a1[j]=0;
			abc(i,a1,1,allt);
			int count=0;
			int big=0;
			for(int x=0;x<i;x++){
				count+=allt[x];
				big=max(big,allt[x]);
			}
			if(big*2<count){
				result+=1;
			}
		}
	}
	cout<<result%998244353;
    return 0;
}