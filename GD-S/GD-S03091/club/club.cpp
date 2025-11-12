#include<bits/stdc++.h>
using namespace std;
int t,n;
struct node{
	int a,b,c,d,e;
};
bool cmp(node a,node b){
	if(a.e==b.e){
		if(a.d==b.d) return a.a+a.b+a.c<b.a+b.b+b.c;
		else return a.d>b.d;
	}else return a.e<b.e;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		int o=0,p=0,q=0,val=0;
		vector<node>a(n);
		for(int i=0;i<n;i++){
			cin>>a[i].a>>a[i].b>>a[i].c;
			a[i].d=max(a[i].a,max(a[i].b,a[i].c));
			a[i].e=min(a[i].a,min(a[i].b,a[i].c));
		}
		sort(a.begin(),a.end(),cmp);
		for(int i=0;i<n;i++){
			int aa=a[i].a,bb=a[i].b,cc=a[i].c,dd=a[i].d;
			if(aa==dd){
				if(o<n/2){
					o++;
					val+=aa;
				}
				else{
					if(bb>cc){
						p++;
						val+=bb;
					}
					else if(bb<cc){
						q++;
						val+=cc;
					}else{
						if(p<q){
							p++;
							val+=bb;
						}else{
							q++;
							val+=cc;
						}
					}
				}
			}else if(bb==dd){
				if(p<n/2){
					p++;
					val+=bb;
				}
				else{
					if(aa>cc){
						o++;
						val+=aa;
					}
					else if(aa<cc){
						q++;
						val+=cc;
					}else{
						if(o<q){
							o++;
							val+=aa;
						}else{
							q++;
							val+=cc;
						}
					}
				}
			}else{
				if(q<n/2){
					q++;
					val+=cc;
				}
				else{
					if(bb>aa){
						p++;
						val+=bb;
					}
					else if(bb<aa){
						o++;
						val+=aa;
					}else{
						if(o<p){
							o++;
							val+=aa;
						}else{
							p++;
							val+=bb;
						}
					}
				}
			}
		}
		cout<<val<<endl;
	}
	return 0;
} 
