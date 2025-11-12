#include<bits/stdc++.h>
using namespace std;
struct node{
	long long a,b,c;
}a[100010];
vector<long long> ga;
vector<long long> gb;
vector<long long> gc;
bool cmpa(long long x,long long y){
	return a[x].a>a[y].a;
}
bool cmpb(long long x,long long y){
	return a[x].b>a[y].b;
}
bool cmpc(long long x,long long y){
	return a[x].c>a[y].c;
}
bool cmpab(long long x,long long y){
	return a[x].a-a[x].b>a[y].a-a[y].b;
}
bool cmpac(long long x,long long y){
	return a[x].a-a[x].c>a[y].a-a[y].c;
}
bool cmpba(long long x,long long y){
	return a[x].b-a[x].a>a[y].b-a[y].a;
}
bool cmpbc(long long x,long long y){
	return a[x].b-a[x].c>a[y].b-a[y].c;
}
bool cmpca(long long x,long long y){
	return a[x].c-a[x].a>a[y].c-a[y].a;
}
bool cmpcb(long long x,long long y){
	return a[x].c-a[x].b>a[y].c-a[y].b;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long t;
	cin >>t;
	while(t--){
		long long n;
		cin >>n;
		ga.clear();
		gb.clear();
		gc.clear();
		for(long long i=1;i<=n;i++){
			cin >>a[i].a>>a[i].b>>a[i].c;
			if(a[i].a>=a[i].b&&a[i].a>=a[i].c)ga.push_back(i);
			else if(a[i].b>=a[i].a&&a[i].b>=a[i].c)gb.push_back(i);
			else  gc.push_back(i);
		}
		if(ga.size()>n/2){
			sort(ga.begin(),ga.end(),cmpab);
			long long o=0,p=0;
			long long cnt=0;
			for(long long i=ga.size()-1;ga.size()-cnt!=n/2;i--){
				o+=a[ga[i]].a-a[ga[i]].b;
				cnt++;
			}
			sort(ga.begin(),ga.end(),cmpac);
			cnt=0;
			for(long long i=ga.size()-1;ga.size()-cnt!=n/2;i--){
				p+=a[ga[i]].a-a[ga[i]].c;
				cnt++;
			}
			if(o<p){
				sort(ga.begin(),ga.end(),cmpab);
				for(long long i=ga.size()-1;i>=0;i--){
					if(ga.size()==n/2)break;
					gb.push_back(ga[i]);
					ga.pop_back();
				}
			}
			else{
				sort(ga.begin(),ga.end(),cmpac);
				for(long long i=ga.size()-1;i>=0;i--){
					if(ga.size()==n/2)break;
					gc.push_back(ga[i]);
					ga.pop_back();
				}
			}
		}
		else if(gb.size()>n/2){
			sort(gb.begin(),gb.end(),cmpba);
			long long o=0,p=0,cnt=0;
			for(long long i=gb.size()-1;gb.size()-cnt!=n/2;i--){
				o+=a[gb[i]].b-a[gb[i]].a;
				cnt++;
			}
			sort(gb.begin(),gb.end(),cmpbc);
			cnt=0;
			for(long long i=gb.size()-1;gb.size()-cnt!=n/2;i--){
				p+=a[gb[i]].b-a[gb[i]].c;
				cnt++;
			}
			if(o<p){
				sort(gb.begin(),gb.end(),cmpba);
				for(long long i=gb.size()-1;i>=0;i--){
					if(gb.size()==n/2)break;
					ga.push_back(gb[i]);
					gb.pop_back();
				}
			}
			else{
				sort(gb.begin(),gb.end(),cmpbc);
				for(long long i=gb.size()-1;i>=0;i--){
					if(gb.size()==n/2)break;
					gc.push_back(gb[i]);
					gb.pop_back();
				}
			}
		}
		else if(gc.size()>n/2){
			sort(gc.begin(),gc.end(),cmpca);
			long long o=0,p=0,cnt=0;
			for(long long i=gc.size()-1;gc.size()-cnt!=n/2;i--){
				o+=a[gc[i]].c-a[gc[i]].a;
				cnt++;
			}
			sort(gc.begin(),gc.end(),cmpcb);
			cnt=0;
			for(long long i=gc.size()-1;gc.size()-cnt!=n/2;i--){
				p+=a[gc[i]].c-a[gc[i]].b;
				cnt++;
			}
			if(o<p){
				sort(gc.begin(),gc.end(),cmpca);
				for(long long i=gc.size()-1;i>=0;i--){
					if(gc.size()==n/2)break;
					ga.push_back(gc[i]);
					gc.pop_back();
				}
			}
			else{
				sort(gc.begin(),gc.end(),cmpcb);
				for(long long i=gc.size()-1;i>=0;i--){
					if(gc.size()==n/2)break;
					gb.push_back(gc[i]);
					gc.pop_back();
				}
			}
		}
		sort(ga.begin(),ga.end(),cmpa);
		sort(gb.begin(),gb.end(),cmpb);
		sort(gc.begin(),gc.end(),cmpc);
		long long s=0;
		for(long long i=0;i<ga.size();i++){
			if(i==n/2)break;
			s+=a[ga[i]].a;
		}
		for(long long i=0;i<gb.size();i++){
			if(i==n/2)break;
			s+=a[gb[i]].b;
		}
		for(long long i=0;i<gc.size();i++){
			if(i==n/2)break;
			s+=a[gc[i]].c;
		}
		cout<<s<<'\n';
	}
	return 0;
}
/*
3 4 4 2 1 3 2 4 5 3 4 3 5 1 4 0 1 0 0 1 0 0 2 0 0 2 0 2 10 9 8 4 0 0
*/
