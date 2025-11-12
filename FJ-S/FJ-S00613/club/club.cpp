#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN=1e5+5;
struct NewNode {
	int a,b,c,x;
	char mx;
	double value;
};
NewNode Node[MAXN];

bool cmp(NewNode a,NewNode b) {
	if(a.mx!=b.mx) return a.mx<b.mx;
	return a.value<b.value;
}

int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--) {
		int n;
		cin>>n;
		int cnt_a=0,cnt_b=0,cnt_c=0;
		for(int i=1; i<=n; i++) {
			cin>>Node[i].a>>Node[i].b>>Node[i].c;
			Node[i].x=max(Node[i].a,max(Node[i].b,Node[i].c));
			if(Node[i].x==Node[i].a) {
				cnt_a++;
				Node[i].mx='a';
			} else if(Node[i].x==Node[i].b) {
				cnt_b++;
				Node[i].mx='b';
			} else if(Node[i].x==Node[i].c) {
				cnt_c++;
				Node[i].mx='c';
			}
		}
		if(cnt_a>n/2||cnt_b>n/2||cnt_c>n/2) {
			for(int i=1; i<=n; i++) {
				Node[i].value=Node[i].x*10000.0/(Node[i].a+Node[i].b+Node[i].c);
			}
			sort(Node+1,Node+n+1,cmp);
			if(cnt_a>n/2) {
				int i=1;
				while(cnt_a>n/2) {
					if(Node[i].b>Node[i].c&&cnt_b+1<=n/2) {
						cnt_b++;
						Node[i].mx='b';
					} else if(cnt_c+1<=n/2) {
						cnt_c++;
						Node[i].mx='c';
					} else {
						cnt_b++;
						Node[i].mx='b';
					}
					cnt_a--;
					i++;
				}
			} else if(cnt_b>n/2) {
				int i=cnt_a+1;
				while(cnt_b>n/2) {
					if(Node[i].a>Node[i].c&&cnt_a+1<=n/2) {
						cnt_a++;
						Node[i].mx='a';
					} else if(cnt_c+1<=n/2) {
						cnt_c++;
						Node[i].mx='c';
					} else {
						cnt_a++;
						Node[i].mx='a';
					}
					cnt_b--;
					i++;
				}
			} else {
				int i=cnt_a+cnt_b+1;
				while(cnt_c>n/2) {
					if(Node[i].a>Node[i].b&&cnt_a+1<=n/2) {
						cnt_a++;
						Node[i].mx='a';
					} else if(cnt_b+1<=n/2) {
						cnt_b++;
						Node[i].mx='b';
					} else {
						cnt_a++;
						Node[i].mx='a';
					}
					cnt_c--;
					i++;
				}
			}
		}
		long long ans=0;
		for(int i=1; i<=n; i++) {
			if(Node[i].mx=='a') ans+=Node[i].a;
			if(Node[i].mx=='b') ans+=Node[i].b;
			if(Node[i].mx=='c') ans+=Node[i].c;
		}
		cout<<ans<<endl;
	}
	return 0;
}
