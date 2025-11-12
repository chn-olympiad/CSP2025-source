#include <bits/stdc++.h>
using namespace std;
int t,n,q[5];
struct stu{
	int a1,a2,a3;
	int n1,p,n2,p2;
}s[100005];
bool cmp(stu x,stu y){
	return x.n1-x.n2<y.n1-y.n2;
}
void ans(){
	int sumn=0;
	for(int i=1;i<=n;++i){
		if(s[i].p==1)  sumn+=s[i].a1;
		else if(s[i].p==2)  sumn+=s[i].a2;
		else  sumn+=s[i].a3;
	}
	cout<<sumn<<'\n';
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		q[1]=0;  q[2]=0;  q[3]=0;
		cin>>n;
		for(int i=1;i<=n;++i){
			cin>>s[i].a1>>s[i].a2>>s[i].a3;
			if(s[i].a1>s[i].a2){
				if(s[i].a1>s[i].a3){
					s[i].p=1;
					s[i].n1=s[i].a1;
					if(s[i].a2>s[i].a3){
						s[i].p2=2;
						s[i].n2=s[i].a2;
					}else{
						s[i].p2=3;
						s[i].n2=s[i].a3;
					}
				}
				else{
					s[i].p=3;
					s[i].n1=s[i].a3;
					s[i].p2=1;
					s[i].n2=s[i].a1;
				}
			}else{
				if(s[i].a2>s[i].a3){
					s[i].p=2;
					s[i].n1=s[i].a2;
					if(s[i].a1>s[i].a3){
						s[i].p2=1;
						s[i].n2=s[i].a1;
					}else{
						s[i].p2=3;
						s[i].n2=s[i].a3;
					}
				}
				else{
					s[i].p=3;
					s[i].n1=s[i].a3;
					s[i].p2=2;
					s[i].n2=s[i].a2;
				}
			}
			++q[s[i].p];
		}
		sort(s+1,s+n+1,cmp);
		if(q[1]>n/2){
			for(int i=1;i<=n;++i){
				if(q[1]==n/2)  break;
				else if(s[i].p==1){
					--q[1];
					s[i].p=s[i].p2;
				}
			}
		}else if(q[2]>n/2){
			for(int i=1;i<=n;++i){
				if(q[2]==n/2)  break;
				else if(s[i].p==2){
					--q[2];
					s[i].p=s[i].p2;
				}
			}
		}else if(q[3]>n/2){
			for(int i=1;i<=n;++i){
				if(q[3]==n/2)  break;
				else if(s[i].p==3){
					--q[3];
					s[i].p=s[i].p2;
				}
			}
		}
		ans();
	}
	return 0;
}
