#include<bits/stdc++.h>
using namespace std;
long long n,k,m[500001],ans=0;
int jinzhi[25]={0,1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576};
bool flag=0;
int vis[500001]={0};
void tepan_a1(){
	if(k!=0||n>2) return;
	for(int i=1;i<=n;i++){
		if(m[i]!=1){
			return;
		}
	}
	if(n==1){
		cout<<0;
		flag=1;
	}
	if(n==2){
		cout<<1;
		flag=1;
	}
	return;
}
void tepan_a2(){
	if(k!=0||n>100) return;
	for(int i=1;i<=n;i++){
		if(m[i]!=1){
			return;
		}
	}
	cout<<n/2;
	flag=1;
	return;
}
int yihuo(int n,int m){
	int vn[25]={0},vm[25]={0},x=0,y=0;
	while(true){
		if(jinzhi[x]>n){
			break;
		}
		x++;
	}
	while(true){
		if(jinzhi[y]>m){
			break;
		}
		y++;
	}
	int nn=n,mm=m;
	for(int i=x;i>0;i--){
		if(nn-jinzhi[i]>=0){
			nn-=jinzhi[i];
			vn[i]=1;
		}
	}
	for(int i=y;i>0;i--){
		if(mm-jinzhi[i]>=0){
			mm-=jinzhi[i];
			vm[i]=1;
		}
	}
	int he=0;
	for(int i=1;i<=max(x-1,y-1);i++){
		if(vn[i]!=vm[i]){
			he+=jinzhi[i];
		}
	}
	
	return he;
}
void biaoji(int x,int y){
	for(int i=x;i<=y;i++){
		vis[i]=1;
	}
}
int jiancha(int x,int y){
	int f=1;
	for(int i=x;i<=y;i++){
		if(vis[i]==1){
			f=0;
		}
	}
	if(f==0) return 0;
	return 1;
}
void tepan_b(){
	if(k>1) return;
	for(int i=1;i<=n;i++){
		if(m[i]>1){
			return;
		}
	}
	int h=0;
	if(k==0){
		for(int i=1;i<=n;i++){
			if(m[i]==0){
				h++;
			}
			if(m[i]==1&&m[i+1]==1){
				h++;
				i=i+1;
			}
		}
	}
	else{
		for(int i=1;i<=n;i++){
			if(m[i]==1){
				h++;
			}
		}
	}
	cout<<h;
	flag=1;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(long long i=1;i<=n;i++){
		cin>>m[i];
		if(m[i]==k){
			ans++;
			vis[i]=1;
		}
	}
	tepan_a1();
	if(flag==1){
		return 0;
	}
	tepan_a2();
	if(flag==1){
		return 0;
	}
	tepan_b();
	if(flag==1){
		return 0;
	}
	for(int l=1;l<=n;l++){
		for(int r=l;r<=n;r++){
			int h=0;
			if(jiancha(l,r)!=1){
				continue;
			}
			for(int i=l;i<=r;i++){
		    	h=yihuo(h,m[i]);
			}
			if(h==k){
				ans++;
			    biaoji(l,r);
			}
		}
	}
	cout<<ans;
	return 0;
}
