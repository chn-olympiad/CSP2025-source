#include<bits/stdc++.h>
using namespace std;
struct Member{
	int fi;
	int se;
	int th;
	bool operator<(const Member m)const{
		if(fi!=m.fi) return fi<m.fi;
		if(se!=m.se) return se<m.se;
		return th<m.th;
	}
	int gmax(){
		return max({fi,se,th});
	}
};
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		priority_queue<Member> mem;
		for(int i=0;i<n;i++){
			int a,b,c;
			scanf("%d %d %d",&a,&b,&c);
			mem.push({a,b,c});
		}
		int sum=0;
		for(int i=0;i<n/2&&mem.size();i++){
			Member nm=mem.top();
			if(nm.gmax()==nm.fi){
				sum+=nm.fi;
				mem.pop();
			}
		}
		for(int i=0;i<n/2&&mem.size();i++){
			Member nm=mem.top();
			if(nm.gmax()==nm.se){
				sum+=nm.se;
				mem.pop();
			}
		}
		for(int i=0;i<n/2&&mem.size();i++){
			Member nm=mem.top();
			sum+=nm.th;
			mem.pop();
		}
		printf("%d\n",sum);
	}
	return 0;
}
