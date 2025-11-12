#include<bits/stdc++.h>
using namespace std;
long long n,a[100005],cnt=0;
bool cheak(long long p[100005],int sk){
	long long maxinum=-1e9,sum=0;
	for(int i=1;i<=sk;i++){
		sum+=p[i];
		maxinum=max(maxinum,p[i]);
	}
	if(sum>maxinum*2){
		return true;
	}
	return false;
}
void polygon(int k,int x,long long p[100005],int sk){
	if(k==0){
		if(cheak(p,sk)==true){
			cnt++;
		}
		return;
	}
	for(int i=x+1;i<=n-k+1;i++){
		p[sk-k+1]=a[i];
		polygon(k-1,i,p,sk);
		p[sk-k+1]=0;	
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	long long p[100005];
	for(int i=1;i<=n;i++){
		polygon(i,0,p,i);
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
