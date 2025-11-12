#include<bits/stdc++.h>
using namespace std;
int mxor(int a,int b){
	int x=a&b;
	int y=a|b;
	return y-x;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n=0,k=0;
	cin>>n>>k;
	vector<int> numbers(n+1,0);
	for(int i=1;i<=n;i++){
		cin>>numbers[i];
	}
	int l=0,r=0;
	int num=0;
	int min_l=0;
	for(r=1;r<=n;r++){
		int sum=0;
		for(l=r;l>min_l;l--){
			sum=mxor(sum,numbers[l]);
			if(sum==k){
				num++;
				min_l=r;
				break;
			}
		}
		
	}
	cout<<num<<endl;
}
