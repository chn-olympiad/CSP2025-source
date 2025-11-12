#include<bits/stdc++.h>
using namespace std;
int n,T;
int a[100005][4];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	/* 
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d %d %d",&a[i][1],&a[i][2],&a[i][3]);
		map<int,int> mp1;
		int cnt1=0;
		map<int,int> mp2;
		int cnt2=0;
		map<int,int> mp3;
		int cnt3=0;
		for(int i=1;i<=n;i++){
			if(max(a[i][1],max(a[i][2],a[i][3]))==a[i][1]){
				mp1[i]=a[i][1];
				cnt1+=a[i][1];
				continue;
			}
			if(max(a[i][1],max(a[i][2],a[i][3]))==a[i][2]){
				mp2[i]=a[i][2];
				cnt2+=a[i][2];
				continue;
			}
			if(max(a[i][1],max(a[i][2],a[i][3]))==a[i][3]){
				mp3[i]=a[i][3];
				cnt3+=a[i][3];
				continue;
			}
		}
		set<int> peo;
		if(mp1.size()>n/2){
			set < pair > st;
			for(auto a:mp1){
				st.insert({mp1[a],a});
			}
			for(auto a:st){
				if(mp1.size()<=n/2)break;
				peo.insert(a.first);
				mp1.erase(a.second);
			}
		}
		if(mp2.size()>n/2){
			
		}
		if(mp3.size()>n/2){
			
		}
	}
	*/
	return 0;
}
