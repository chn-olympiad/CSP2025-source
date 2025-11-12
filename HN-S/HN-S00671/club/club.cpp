#include<bits/stdc++.h>
using namespace std;
int t,q,w,e,qqq;
struct aa{
	int km1,km2,km3,num,f,ans,al;
}a[100010];
bool cmp(aa l,aa r){
	return l.al<r.al;
}
bool huifu(aa l,aa r){
	return l.ans<r.ans;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		memset(a,0,sizeof(a));
		q=w=e=0;
		int n;
		cin>>n;
		int v=n/2;
		for(int i=1;i<=n;i++){
			a[i].ans=i;
			cin>>a[i].km1>>a[i].km2 >>a[i].km3;
			a[i].num=max(a[i].km1,max(a[i].km2,a[i].km3));
		}
		for(int i=1;i<=n;i++){
			if(a[i].num==a[i].km1){
				q++;
				a[i].f=a[i].km1;
			}else if(a[i].num==a[i].km2){
				w++;
				a[i].f=a[i].km2;
			}else if(a[i].num==a[i].km3){
				e++;
				a[i].f=a[i].km3;
			}
		}
		if(n/2<q){
			for(int i=1;i<=n;i++){
				if(a[i].f==a[i].km1){
					a[i].al=a[i].km1-max(a[i].km2,a[i].km3);
				}else a[i].al=INT_MAX-1;
			}sort(a+1,a+1+n,cmp);
			for(int i=1;i<=q;i++){
				if(a[i].km2>=a[i].km3){
					if(w+1<=v){
						q--,w++;
						a[i].f=a[i].km2;
					}
				}else{
					if(e+1<=n/2){
						q--,e++;
						a[i].f=a[i].km3;
					}
				}
				if(n/2>=q)break;
			}
			if(n/2<q){
				for(int i=1;i<=q;i++){
					if(a[i].km2<=a[i].km3){
						if(w+1<=n/2){
							q--,w++;
							a[i].f=a[i].km2;
						}
					}else{
						if(e+1<=n/2){
							q--,e++;
							a[i].f=a[i].km3;
						}
					}if(n/2>=q)break;
				}
			}
		}else if(n/2<w){
			for(int i=1;i<=n;i++){
				if(a[i].f==a[i].km2){
					a[i].al=a[i].km2-max(a[i].km1,a[i].km3);
				}else a[i].al=INT_MAX-1;
			}sort(a+1,a+1+n,cmp);
			for(int i=1;i<=w;i++){
				if(a[i].km1>=a[i].km3){
					if(q+1<=n/2){
						q++,w--;
						a[i].f=a[i].km1;
					}
				}else{
					if(e+1<=n/2){
						w--,e++;
						a[i].f=a[i].km3;
					}
				}if(n/2>=w)break;
			}
			if(n/2<w){
				for(int i=1;i<=w;i++){
					if(a[i].km1<=a[i].km3){
						if(q+1<=n/2){
							q++,w--;
							a[i].f=a[i].km1;
						}
					}else{
						if(e+1<=n/2){
							w--,e++;
							a[i].f=a[i].km3;
						}
					}if(n/2>=w)break;
				}
			}
		}else if(n/2<e){
			for(int i=1;i<=n;i++){
				if(a[i].f==a[i].km3){
					a[i].al=a[i].km3-max(a[i].km2,a[i].km1);
				}else a[i].al=INT_MAX-1;
			}sort(a+1,a+1+n,cmp);
			for(int i=1;i<=e;i++){
				if(a[i].km2>=a[i].km1){
					if(w+1<=n/2){
						e--,w++;
						a[i].f=a[i].km2;
					}
				}else{
					if(q+1<=n/2){
						q++,e--;
						a[i].f=a[i].km1;
					}
				}if(n/2>=e)break;
			}
			if(n/2<e){
				for(int i=1;i<=e;i++){
					if(a[i].km2<=a[i].km1){
						if(w+1<=n/2){
							e--,w++;
							a[i].f=a[i].km2;
						}
					}else{
						if(q+1<=n/2){
							q++,e--;
							a[i].f=a[i].km1;
						}
					}if(n/2>=e)break;
				}
			}
		}qqq=0;
		for(int i=1;i<=n;i++){
			qqq+=a[i].f;
		}cout<<qqq<<endl;
	}
	return 0;
} 
/*



*/
