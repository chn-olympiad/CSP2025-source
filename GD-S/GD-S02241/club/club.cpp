#include<bits/stdc++.h>
using namespace std;
int t,n,a,b,c,d;
long long ans;
int nm1,nm2,nm3,t1[100005],t2[100005],t3[100005];

void up1(int x,int now){
	t1[now]=x;
	while(now>1){
		if(t1[now]<t1[now/2]) swap(t1[now],t1[now/2]),now/=2;
		else return;
	}
}
void up2(int x,int now){
	t2[now]=x;
	while(now>1){
		if(t2[now]<t2[now/2]) swap(t2[now],t2[now/2]),now/=2;
		else return;
	}
}
void up3(int x,int now){
	t3[now]=x;
	while(now>1){
		if(t3[now]<t3[now/2]) swap(t3[now],t3[now/2]),now/=2;
		else return;
	}
}

void down1(int now){
	t1[now]=t1[nm1],nm1--;
	while(now<=nm1){
		int y=now*2;
		if(y+1<=nm1&&t1[y+1]<t1[y]) y++;
		if(y>nm1) return; 
		if(t1[now]>t1[y]) swap(t1[now],t1[y]),now=y;
		else return;
	}
}
void down2(int now){
	t2[now]=t2[nm2],nm2--;
	while(now<=nm2){
		int y=now*2;
		if(y+1<=nm2&&t2[y+1]<t2[y]) y++;
		if(y>nm2) return; 
		if(t2[now]>t2[y]) swap(t2[now],t2[y]),now=y;
		else return;
	}
}
void down3(int now){
	t3[now]=t3[nm3],nm3--;
	while(now<=nm3){
		int y=now*2;
		if(y+1<=nm3&&t3[y+1]<t3[y]) y++;
		if(y>nm3) return; 
		if(t3[now]>t3[y]) swap(t3[now],t3[y]),now=y;
		else return;
	}
}


int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		ans=0;
		for(int i=1;i<=n;i++){
			cin>>a>>b>>c;
			if(a>=b&&a>=c){
				d=max(b,c);
				if(nm1+1<=n/2){
					nm1++,up1(a-d,nm1);
					ans+=a;
				}else{
					if(t1[1]<a-d){
						ans=ans-t1[1]+a;
						down1(1);
						nm1++,up1(a-d,nm1);
					}else ans+=d;
				}
			}else if(b>=a&&b>=c){
				d=max(a,c);
				if(nm2+1<=n/2){
					nm2++,up2(b-d,nm2);
					ans+=b;
				}else{
					if(t2[1]<b-d){
						ans=ans-t2[1]+b;
						down2(1);
						nm2++,up2(b-d,nm2);
					}else ans+=d;
				}
			}else{
				d=max(b,a);
				if(nm3+1<=n/2){
					nm3++,up3(c-d,nm3);
					ans+=c;
				}else{
					if(t3[1]<c-d){
						ans=ans-t3[1]+c;
						down3(1);
						nm3++,up3(c-d,nm3);
					}else ans+=d;
				}
			}
		}
		while(nm1>0) down1(1);
		while(nm2>0) down2(1);
		while(nm3>0) down3(1);
		cout<<ans<<endl;
	}
	return 0;
}
