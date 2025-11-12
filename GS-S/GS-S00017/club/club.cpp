#include <bits/stdc++.h>

using namespace std;

int t,n,limit,club[3]={0};


class stu{
public:
	int v[3]={0},mv[3]={0,1,2};
	stu() {}
	stu(int aa,int bb,int cc){
		v[0]=aa;v[1]=bb;v[2]=cc;
		#define m3(a,b,c) {mv[0]=a;mv[1]=b;mv[2]=c;}
		
		if (aa>=bb) {
			if (aa>=cc) {
				if (bb>=cc) m3(0,1,2)
				else m3(0,2,1)
			}else m3(2,0,1)
		} else {
			if (cc>=bb) m3(2,1,0)
			else {
				if (aa>=cc) m3(1,0,2)
				else m3(1,2,0)
			}
		}
		
	}
	
	
	int get() {
		if (club[mv[0]]!=limit) return mv[0];
		else if (club[mv[1]]!=limit) return mv[1];
		else return mv[2];
	}
	
	int operator<(stu other) {
		return other.v[other.get()]-this->v[this->get()];
	}
};
struct stu stuu[100010];





int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>t;
	while (t--) {
		int ans=0;
		memset(club,0,sizeof(club));
		cin>>n;
		limit=n/2;
		for (int i=0,a,b,c;i<n;i++) {
			cin>>a>>b>>c;
			stuu[i]=stu(a,b,c);
		}
		sort(stuu,stuu+n-1);
		int i=0;
		for (;i<n;i++) {
			stu& temp=stuu[i];
			int j=temp.get();
			ans+=temp.v[j];
			if (++club[j]==limit) {i++;break;}
		}
		if (i<n) {
			sort(&stuu[i],&stuu[n-1]);
			for (;i<n;i++) {
				stu& temp=stuu[i];
				ans+=temp.v[temp.get()];
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}


