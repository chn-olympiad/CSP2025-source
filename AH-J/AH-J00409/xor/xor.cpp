#include<bits/stdc++.h>
using namespace std;
int a[500005],k,n,b,cnt,cnt1,s=-1;
bool f,B=true,A=true;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1&&a[i]!=0)B=false;
		if(a[i]!=1)A=false;
	}
	if(k==0&&A)cout<<n;
	else if(k==1&&B){
		for(int i=1;i<=n;i++){
			if(a[i]==1)cnt++;
		}
		cout<<cnt;
	}else{
		for(int i=1;i<=n;i++){
			if(s!=-1)s=(s^a[i]);
			else s=a[i];
			if(s==k){
				s=-1;
				cnt++;
			}
		}
		cout<<cnt;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
