#include<bits/stdc++.h>
using namespace std;
long long n,a[500005],k,qz[500005],ans,ans1,ans2,head1=0,pos1=1,head=0,pos=1,bj[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) a[i]=-1;
	a[0]=0;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1) ans1++;
		if(a[i]==0) ans2++;
	}
	if(ans1+ans2==n){
		if(k==1) cout<<ans1;
		if(k==0) cout<<ans2;
		exit(0);
	}
	for(long long i=1;i<=n;i++){
		if(a[i]==k) ans++,head1=i+1,pos1=head1+1;
		if(i-1<head1) qz[i]=0^a[i];
		else qz[i]=qz[i-1]^a[i];
		//cout<<"head1:"<<head1<<","<<"pos1:"<<pos1<<endl;
		//cout<<i<<" "<<a[i]<<","<<qz[i]<<"*"<<endl;
	}
	//pos++;
	if(ans1==n){cout<<n;exit(0);}
	for(long long i=1;i<=n;i++){
		if(qz[pos]-qz[head]==k){
			//for(int j=head;j<=pos;j++) bj[j]=1;
			head=i+1,pos=head+1;
			if(pos<=n&&head<=n) ans++;
			//cout<<head<<","<<pos<<","<<ans<<endl;
		}
		else{
			pos++;
			continue;
		}
	}
	cout<<ans;
	fclose(stdin),fclose(stdout);
	return 0;
}