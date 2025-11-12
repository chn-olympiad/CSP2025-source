#include<bits/stdc++.h>
using namespace std;
int t,n,m,num[5];
bool flag=0;
struct node{
	int x,y,z;
};
int cdpd(int a,int b,int c){
	if(a<b){
		swap(a,b);
	}
	else if(b<c){
		swap(b,c);
	}
	else if(a<b){
		swap(a,b);
	}
	return b;
}
bool cmp(node f,node e){
	int a=max(max(f.x,f.y),f.z),b=max(max(e.x,e.y),e.z),c=min(min(f.x,f.y),f.z),d=min(min(e.x,e.y),e.z),p,q;
	if(a>b){
		return 1;
	}
	else if(a==b){
		if(f.x<a && f.x>c){
			p=f.x;
		}
		else if(f.y<a && f.y>c){
			p=f.y;
		}
		else if(f.z<a && f.z>c){
			p=f.z;
		}
		if(e.x<a && e.x>c){
			q=f.x;
		}
		else if(e.y<a && e.y>c){
			q=e.y;
		}
		else if(e.z<a && e.z>c){
			q=e.z;
		}
	}
	else if(p==q){
		return c<d;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--){
		node a[100005];
		cin>>n;
		int sum=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
		}
		sort(a+1,a+n+1,cmp);
		int num1=0,num2=0,num3=0;
		for(int i=1;i<=n;i++){
			m=max(max(a[i].x,a[i].y),a[i].z);
			if(a[i].x==a[i].y==m){
				sum+=m;
				continue;
			}
			else if(a[i].y==a[i].z==m){
				sum+=m;
				continue;
			}
			else if(a[i].x==a[i].z==m){
				sum+=m;
				continue;
			}
			if(a[i].x==m){
				if(num1>=n/2){
					sum+=cdpd(a[i].x,a[i].y,a[i].z);
					continue;
				}
				num1++;
				sum+=m;
			}
			else if(a[i].y==m){
				if(num2>=n/2){
					sum+=cdpd(a[i].x,a[i].y,a[i].z);
					continue;
				}
				num2++;
				sum+=m;
			}
			else if(a[i].z==m){
				if(num3>=n/2){
					sum+=cdpd(a[i].x,a[i].y,a[i].z);
					continue;
				}
				num3++;
				sum+=m;
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
