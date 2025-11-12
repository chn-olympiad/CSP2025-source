#include<bits/stdc++.h>
using namespace std;
int t,n,mid,x,y,z,sum;
struct Node{
	int a,b,c,li,li2,li3,ck,ck2;
	char op;
}a[500010];
bool cmp(Node a,Node b){
	if(a.ck!=b.ck){
		return a.ck>b.ck;
	}else if(a.ck2!=b.ck2){
		return a.ck2>b.ck2;
	}else if(a.li!=b.li){
		return a.li>b.li;
	}else if(a.li2!=b.li2){
		return a.li2>b.li2;
	}else{
		return a.li3>b.li3;
	} 
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		x=y=z=sum=0;
		cin>>n;
		mid=n/2;
		for(int i=1;i<=n;i++){
			cin>>a[i].a>>a[i].b>>a[i].c;
			a[i].li=max({a[i].a,a[i].b,a[i].c});
			a[i].li2=a[i].a+a[i].b+a[i].c-max({a[i].a,a[i].b,a[i].c})-min({a[i].a,a[i].b,a[i].c});
			a[i].li3=min({a[i].a,a[i].b,a[i].c});
			a[i].ck=max({a[i].a,a[i].b,a[i].c})-(a[i].a+a[i].b+a[i].c-max({a[i].a,a[i].b,a[i].c})-min({a[i].a,a[i].b,a[i].c}));
			a[i].ck2=(a[i].a+a[i].b+a[i].c-max({a[i].a,a[i].b,a[i].c})-min({a[i].a,a[i].b,a[i].c})-min({a[i].a,a[i].b,a[i].c}));
			a[i].op==(max({a[i].a,a[i].b,a[i].c})==a[i].a?'a':(max({a[i].a,a[i].b,a[i].c})==a[i].b?a[i].b:a[i].c));
//			cout<<a[i].a<<' '<<a[i].b<<' '<<a[i].c<<' '<<a[i].ck<<' '<<a[i].ck2<<' '<<a[i].li<<' '<<a[i].li2<<' '<<a[i].li3<<endl;
//			cout<<a[i].a<<' '<<a[i].b<<' '<<a[i].c<<' '<<a[i].li<<' '<<a[i].ck<<endl;
		}
		sort(a+1,a+n+1,cmp);
//		for(int i=1;i<=n;i++){
//			cout<<a[i].a<<' '<<a[i].b<<' '<<a[i].c<<' '<<a[i].ck<<' '<<a[i].ck2<<' '<<a[i].li2<<' '<<a[i].li3<<endl;
//		}
		for(int i=1;i<=n;i++){
			if(a[i].li==
			a[i].a){
				if(x<mid){
					x++;
					sum+=a[i].a;
				}else{
					if(a[i].li2==a[i].b){
						if(y<mid){
							y++;
							sum+=a[i].b;
						}else{
							z++;
							sum+=a[i].c;
						}
					}else{
						if(z<mid){
							z++;
							sum+=a[i].c;
						}else{
							y++;
							sum+=a[i].b;
						}
					}
				}
			}else if(a[i].li==a[i].b){
				if(y<mid){
					y++;
					sum+=a[i].b;
				}else{
					if(a[i].li2==a[i].a){
						if(x<mid){
							x++;
							sum+=a[i].a;
						}else{
							z++;
							sum+=a[i].c;
						}
					}else{
						if(z<mid){
							z++;
							sum+=a[i].c;
						}else{
							x++;
							sum+=a[i].a;
						}
					}
				}
			}else{
				if(z<mid){
					z++;
					sum+=a[i].c;
				}else{
					if(a[i].li2==a[i].a){
						if(x<mid){
							x++;
							sum+=a[i].a;
						}else{
							y++;
							sum+=a[i].b;
						}
					}else{
						if(y<mid){
							y++;
							sum+=a[i].b;
						}else{
							x++;
							sum+=a[i].a;
						}
					}
				}
			}
//			cout<<a[i].a<<' '<<a[i].b<<' '<<a[i].c<<' '<<a[i].ck<<' '<<a[i].ck2<<' '<<a[i].li<<' '<<a[i].li2<<' '<<a[i].li3<<' '<<sum<<endl;
		}
		cout<<sum<<endl;
	}
	return 0;
}
