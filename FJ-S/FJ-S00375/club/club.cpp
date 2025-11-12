#include<bits/stdc++.h>
using namespace std;
int t,n;
struct club{
	int a,b,c;
	int fi,se,th;
	char bj;
};
bool cmp1(club x,club y){
	return min(x.a-x.b,x.a-x.c)<min(y.a-y.b,y.a-y.c);
}
bool cmp2(club x,club y){
	return min(x.b-x.a,x.b-x.c)<min(y.b-y.a,y.b-y.c);
}
bool cmp3(club x,club y){
	return min(x.c-x.a,x.c-x.b)<min(y.c-y.a,y.c-y.b);
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		club A[n+1];
		for(int i=1;i<=n;i++){
			cin>>A[i].a>>A[i].b>>A[i].c;
			int maxn=max(max(A[i].a,A[i].b),A[i].c),minn=min(min(A[i].a,A[i].b),A[i].c);
			if(A[i].a==maxn&&A[i].b==minn||A[i].a==minn&&A[i].b==maxn){
				if(A[i].a==maxn&&A[i].b==minn){
					A[i].fi=A[i].a;
					A[i].se=A[i].c;
					A[i].th=A[i].b;
					A[i].bj='a';
				}else{
					A[i].fi=A[i].b;
					A[i].se=A[i].c;
					A[i].th=A[i].a;
					A[i].bj='b';
				}
			}else if(A[i].a==maxn&&A[i].c==minn||A[i].a==minn&&A[i].c==maxn){
				if(A[i].a==maxn&&A[i].c==minn){
					A[i].fi=A[i].a;
					A[i].se=A[i].b;
					A[i].th=A[i].c;
					A[i].bj='a';
				}else{
					A[i].fi=A[i].c;
					A[i].se=A[i].b;
					A[i].th=A[i].a;
					A[i].bj='c';
				}
			}else if(A[i].b==maxn&&A[i].c==minn||A[i].b==minn&&A[i].c==maxn){
				if(A[i].b==maxn&&A[i].c==minn){
					A[i].fi=A[i].b;
					A[i].se=A[i].a;
					A[i].th=A[i].c;
					A[i].bj='b';
				}else{
					A[i].fi=A[i].c;
					A[i].se=A[i].a;
					A[i].th=A[i].b;
					A[i].bj='c';
				}
			}
		}
		int az=0,bz=0,cz=0;
		for(int i=1;i<=n;i++){
			if(A[i].fi==A[i].a){
				az++;
			}else if(A[i].fi==A[i].b){
				bz++;
			}else if(A[i].fi==A[i].c){
				cz++;
			}
		}
		if(az>n/2){
			int sum=az-n/2;
			sort(A+1,A+n+1,cmp1);
			int cnt=0;
			for(int i=1;i<=n;i++){
				if(sum!=0){
					if(A[i].bj=='a'){
						sum--;
						cnt+=max(A[i].b,A[i].c);
					}else{
						cnt+=A[i].fi;
					}
				}else{
					cnt+=A[i].fi;
				}
			}
			cout<<cnt<<'\n';
		}else if(bz>n/2){
			int sum=bz-n/2;
			sort(A+1,A+n+1,cmp2);
			int cnt=0;
			for(int i=1;i<=n;i++){
				if(sum!=0){
					if(A[i].bj=='b'){
						sum--;
						cnt+=max(A[i].a,A[i].c);
					}else{
						cnt+=A[i].fi;
					}
				}else{
					cnt+=A[i].fi;
				}
			}
			cout<<cnt<<'\n';
		}else if(cz>n/2){
			int sum=cz-n/2;
			sort(A+1,A+n+1,cmp3);
			int cnt=0;
			for(int i=1;i<=n;i++){
				if(sum!=0){
					if(A[i].bj=='c'){
						sum--;
						cnt+=max(A[i].a,A[i].b);
					}else{
						cnt+=A[i].fi;
					}
				}else{
					cnt+=A[i].fi;
				}
			}
			cout<<cnt<<'\n';
		}else{
			int cnt=0;
			for(int i=1;i<=n;i++){
				cnt+=A[i].fi;
			}
			cout<<cnt<<'\n';
		}
	}
	return 0;
}
