#include<bits/stdc++.h>
using namespace std;
int t;
struct p {
	int x1,x2,x3;
	int c;
	bool flag=0;
}a1[100020],a2[100020];
bool cmp1(p x,p y) {return x.c>y.c;}
bool cmp2(p x,p y) {return x.x2>y.x2;}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while (t--) {
		int n;
		cin>>n;
		int sum=0;
		for (int i=0;i<n;i++) {
			cin>>a1[i].x1>>a1[i].x2>>a1[i].x3;
			a1[i].flag=0;
			sum+=a1[i].x1;
			a2[i]=a1[i];
			a1[i].c=a1[i].x2-a1[i].x1;
			a2[i].c=a2[i].x3-a2[i].x1;
		}
		sort(a1,a1+n,cmp1);
		sort(a2,a2+n,cmp1);
		int p=n;
		int p1=0,p2=0;
		while ((p>n/2||a1[p1].c>0||a2[p2].c>0)&&p>0) {
			if (a1[p1].c>a2[p2].c&&p1<n/2&&a1[p1].flag==0) {
				sum+=a1[p1].c;
				p1++;
			}
			else if (p2<n/2&&a2[p2].flag==0) {
				sum+=a2[p2].c;
				p2++;
			}
			p--;
			if (p1==n/2&&p2==n/2) break;
		}
		cout<<sum<<"\n";
	}
	return 0;
}

