#include<bits/stdc++.h>
using namespace std;
struct qp{
	int x,k;
}a[100005],b[100005],c[100005];
int t,n;
long long sum;
bool cmp(qp q,qp p){
	return q.x>p.x;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        sum=0;
    	cin>>n;
    	for(int i=1;i<=n;i++){
    		cin>>a[i].x>>b[i].x>>c[i].x;
    		a[i].k=i;
    		b[i].k=i;
    		c[i].k=i;
		}
		sort(a+1,a+n+1,cmp);
		sort(b+1,b+n+1,cmp);
		sort(c+1,c+n+1,cmp);
		int j=0,q=0,l=0,p=n;
		while(n--){
			if(a[j].x>=b[q].x&&a[j].x>=c[l].x&&j<p/2){
				sum+=a[++j].x;
				if(a[j].k==b[q].k) q--;
				if(a[j].k==c[l].k) l--;
			}else if(a[j].x<=b[q].x&&b[q].x>=c[l].x&&q<p/2){
				sum+=b[++q].x;
				if(a[j].k==b[q].k) j--;
				if(b[q].k==c[l].k) l--;
			}else if(l<p/2){
				sum+=c[++l].x;
				if(c[l].k==b[q].k) q--;
				if(a[j].k==c[l].k) j--;
			}
		}
		cout<<sum<<endl;
	}
    return 0;
}