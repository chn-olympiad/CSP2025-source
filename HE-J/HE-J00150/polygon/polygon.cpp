#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,d=0,sum=0,maxn=0,mm,num=0;
	cin>>n;
	for(int i=0;i<=n-1;i++){
		cin>>mm;
		for(int j=i+1;j<=n-1;j++){
			if(mm>maxn){
				maxn=mm;
			}
			sum+=mm;
			num++;
			if(sum>maxn){
				d++;
				d%=998;
				d%=244;
				d%=353;
			}
		}
	}
	cout<<d;
	return 0;
}
