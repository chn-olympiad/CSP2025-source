#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t,n,a[N][5],bn=0;
struct node{
	int id,id1,id2,id3,c2,c3;
}b[N];
bool cmp(node A,node B){
	if(A.c2==B.c2)return A.c3>B.c3;
	return A.c2>B.c2;
}
int main () {
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t--){
		bn=0;
		long long sum=0;
		int a1=0,b1=0,c1=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			sum+=max(a[i][1],max(a[i][2],a[i][3]));
			if(a[i][1]==max(a[i][1],max(a[i][2],a[i][3]))){
				a1++;
				b[++bn].id=i;
				b[bn].id1=1;
				if(a[i][2]>a[i][3]){
					b[bn].id2=2;
					b[bn].id3=3;
					b[bn].c2=a[i][2]-a[i][1];
					b[bn].c3=a[i][3]-a[i][1];
				}else{
					b[bn].id2=3;
					b[bn].id3=2;
					b[bn].c2=a[i][3]-a[i][1];
					b[bn].c3=a[i][2]-a[i][1];
				}
			}else if(a[i][2]==max(a[i][1],max(a[i][2],a[i][3]))){
				      b1++;
				      b[++bn].id=i;
				      b[bn].id1=2;
				      if(a[i][1]>a[i][3]){
					      b[bn].id2=1;
					      b[bn].id3=3;
					      b[bn].c2=a[i][1]-a[i][2];
					      b[bn].c3=a[i][3]-a[i][2];
				      }else{
					      b[bn].id2=3;
					      b[bn].id3=1;
					      b[bn].c2=a[i][3]-a[i][2];
					      b[bn].c3=a[i][1]-a[i][2];
				      }
			      }else{
					  c1++;
					  b[++bn].id=i;
					  b[bn].id1=3;
				      if(a[i][1]>a[i][2]){
					      b[bn].id2=1;
					      b[bn].id3=2;
					      b[bn].c2=a[i][1]-a[i][3];
					      b[bn].c3=a[i][2]-a[i][3];
				      }else{
					      b[bn].id2=2;
					      b[bn].id3=1;
					      b[bn].c2=a[i][2]-a[i][3];
					      b[bn].c3=a[i][1]-a[i][3];
				      }
				  }
		}
		sort(b+1,b+1+bn,cmp);
		for(int i=1;i<=bn;i++){
			if(b[i].id1==1){
				if(a1<=n/2)continue;
				if((b[i].id2==2&&b1<n/2)||(b[i].id2==3&&c1<n/2)){
					sum+=b[i].c2;
					b1++;
				}else{
					sum+=b[i].c3;
					c1++;
				}
				a1--;
			}
			if(b[i].id1==2){
				if(b1<=n/2)continue;
				if((b[i].id2==1&&a1<n/2)||(b[i].id2==2&&b1<n/2)){
					sum+=b[i].c2;
					a1++;
				}else{
					sum+=b[i].c3;
					c1++;
				}
				b1--;
			}
			if(b[i].id1==3){
				if(c1<=n/2)continue;
				if((b[i].id2==1&&a1<n/2)||(b[i].id2==2&&b1<n/2)){
					sum+=b[i].c2;
					a1++;
				}else{
					sum+=b[i].c3;
					b1++;
				}
				c1--;
			}
	    }
	    cout<<sum<<endl;
	}
    return 0;
}
