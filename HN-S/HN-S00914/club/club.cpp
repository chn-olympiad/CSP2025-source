#include<bits/stdc++.h>
using namespace std;
struct aa{
	int a,b,c,d,e,f,g;
	bool x=1;
};
bool cmp1(aa a,aa b){
	if(a.g!=1){
		return 0;
	}
	if(b.g!=1){
		return 1;
	}
	return(a.e>a.f?a.e:a.f)>(b.e>b.f?b.e:b.f);
}
bool cmp2(aa a,aa b){
	if(a.g!=2){
		return 0;
	}
	if(b.g!=2){
		return 1;
	}
	return(a.d>a.f?a.d:a.f)>(b.d>b.f?b.d:b.f);
}
bool cmp3(aa a,aa b){
	if(a.g!=3){
		return 0;
	}
	if(b.g!=3){
		return 1;
	}
	return(a.e>a.d?a.e:a.d)>(b.e>b.d?b.e:b.d);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T,n;
	cin>>T;
	
	while(T--){
		cin>>n;int a=0,b=0,c=0,d[100000]={},m=n/2,e[100000]={},ans=0;
		aa aa[n];
		for(int i=0;i<n;i++){
			cin>>aa[i].a>>aa[i].b>>aa[i].c;
			aa[i].x=1;
			//cout<<';'<<aa[i].a<<' '<<aa[i].b<<' '<<aa[i].c<<' ';
			if(aa[i].a>=aa[i].b&&aa[i].a>=aa[i].c){
				ans+=aa[i].a;
				aa[i].g=1;
				a++;
				aa[i].d=0;
				aa[i].e=aa[i].b-aa[i].a;
				aa[i].f=aa[i].c-aa[i].a;
				//cout<<1;
			}else if(aa[i].b>=aa[i].a&&aa[i].b>=aa[i].c){
				ans+=aa[i].b;
				aa[i].g=2;
				b++;
				aa[i].e=0;
				aa[i].d=aa[i].a-aa[i].b;
				aa[i].f=aa[i].c-aa[i].b;
				//cout<<2;
			}else if(aa[i].c>=aa[i].b&&aa[i].c>=aa[i].a){
				ans+=aa[i].c;
				aa[i].g=3;
				c++;
				aa[i].f=0;
				aa[i].d=aa[i].a-aa[i].c;
				aa[i].e=aa[i].b-aa[i].c;
				//cout<<3;
			}
			//cout<<' ';
		}
		//cout<<ans<<endl;
		if(a<=m&&b<=m&&c<=m){
			
		}else{
			if(a>m){
				//cout<<1;
				sort(aa,aa+n,cmp1);
				int i=0;
				while(a>m){
					a--;
					ans+=max(aa[i].e,aa[i].f);i++;
					//cout<<min(aa[i].e,aa[i].f)<<endl;
				}
			}else if(b>m){
				//cout<<1;
				sort(aa,aa+n,cmp2);
				int i=0;
				while(b>m){
					b--;
					ans+=max(aa[i].d,aa[i].f);i++;
					//cout<<min(aa[i].d,aa[i].f)<<endl;
				}
			}else {//cout<<1;
				sort(aa,aa+n,cmp3);
				int i=0;
				while(c>m){
					c--;
					ans+=max(aa[i].d,aa[i].e);i++;
					//cout<<min(aa[i].d,aa[i].e)<<endl;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 
