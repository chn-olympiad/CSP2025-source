#include<bits/stdc++.h>
using namespace std;
#define int long long
int in(){
	int k=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c<='9'&&c>='0'){
		k*=10;
		k+=c-'0';
		c=getchar();
	}
	return k*f;
}

const int N=1e5+7;
int n,c1,c2,c3,sum,f=0;
struct node{
	int x,y;
	int id_x,id_y;
	int id;
}a[N];

struct L{
	int val,id;
};
bool cmp1(L x,L y){
	return x.val>y.val;
}

bool cmp(node x,node y){
	if(x.x+y.y==x.y+y.x){
		return x.x>y.x;
	}
	return x.x+y.y>x.y+y.x;
}
void solve(){
	c1=0,c2=0,c3=0,sum=0,f=0;
	n=in();
	for(int i=1;i<=n;i++){
		L l[3];
		l[1].val=in();
		l[1].id=1;
		l[2].val=in();
		l[2].id=2;
		l[3].val=in();
		l[3].id=3;
		sort(l+1,l+1+3,cmp1);
		a[i].x=l[1].val;
		a[i].id_x=l[1].id;
		a[i].y=l[2].val;
		a[i].id_y=l[2].id;	
		a[i].id=i;
	}
	for(int i=1;i<=n;i++){
		if(a[i].id_x==1)c1++;
		else if(a[i].id_x==2)c2++;
		else c3++;
	}
	if(c1>n/2||c2>n/2||c3>n/2){
		f=1;
		sort(a+1,a+1+n,cmp);
		if(c1>n/2){
			c1=n/2;
			for(int i=1;i<=n;i++){
				if(a[i].id_x==1){
					if(c1){
						sum+=a[i].x;
						c1--;
					}else{
						sum+=a[i].y;
					}
				}else{
					sum+=a[i].x;
				}
			}
		}else if(c2>n/2){
			c2=n/2;
			for(int i=1;i<=n;i++){
				if(a[i].id_x==2){
					if(c2){
						sum+=a[i].x;
						c2--;
					}else{
						sum+=a[i].y;
					}
				}else{
					sum+=a[i].x;
				}
			}	
		}else{
			c3=n/2;
			for(int i=1;i<=n;i++){
				if(a[i].id_x==3){
					if(c3){
						sum+=a[i].x;
						c3--;
					}else{
						sum+=a[i].y;
					}
				}else{
					sum+=a[i].x;
				}
			}
		}
	}else{
		for(int i=1;i<=n;i++)sum+=a[i].x;
	}
	cout<<sum<<"\n";
	return ;
}

signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    int t;
	cin>>t;
	while(t--){
		solve();
	}	
	return 0;
} 
