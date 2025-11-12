#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,num,bj2=0,sum=0;
	cin>>n>>m;
	num=n;
	char a[10000];
	int b[10000],bj=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]-'0'==0){
			num--;
		}
	}
	num-=m;
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	sort(b+1,b+n+1);
	for(int i=1;i<=n;i++){
		if(b[i+1]==b[i])sum++;
		if(i==n)sum++;
		if(a[i]-'0'==0){
			bj++;
			bj2++;
			num--;
		}else{
			bj2=0;
		}
		if(b[bj]<bj2){
			bj++;
			num--;
		}	
		if(n-bj>num){
			swap(b[bj],b[bj-1]);
			i-=2;
			num++;
		}
	}
	cout<<sum;
	return 0;
}
