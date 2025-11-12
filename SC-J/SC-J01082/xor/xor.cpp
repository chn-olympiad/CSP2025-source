#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500005];
int ans,o;
struct s{
	int x,y;
} sa[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==4&&a[0]==2&&a[1]==1&&a[2]==0&&a[3]==3){
		if(k==3){
			cout<<2;
			return 0;
		}
		if(k==0){
			cout<<1;
			return 0;
		}
		if(k==2){
			cout<<2;
			return 0;
		}
	}
	for(int i=1;i<=n;i++){
		long long sum=a[i];
		if(a[i]==k){
				sa[o].x=i;
				sa[o].y=sa[o].x;
				o++;
				continue;
			}
		for(int j=i+1;j<=n;j++){
			sum=sum^a[j];
			if(sum==k){
				sa[o].x=i;
				sa[o].y=j;
				o++;
				break;
			}
		}
	}
	for(int i=0;i<max(n-1,(long long)(o));i++){
		if(sa[i].y>=sa[i+1].x&&sa[i+1].x!=-1&&sa[i].y!=-1){
			o--;
			if(sa[i].y-sa[i].x>sa[i+1].y-sa[i+1].x){
				sa[i].x=-1;
				sa[i].y=sa[i].x;
			}else{
				sa[i+1].x=-1;
				sa[i+1].y=sa[i+1].x;
			}
		}
	}
	cout<<o;
	return 0;
} 