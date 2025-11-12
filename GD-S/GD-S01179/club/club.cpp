#include <bits/stdc++.h>
using namespace std;
int t,n,a[100034][3],ans,max_people;
//vector<int> s(50034,-34);
//vector<vector<vector<vector<vector<int>>>>> awa(50034,vector<50034,vector<50034,vector<100034,vector<50034,vector<100034,s>>>>);
int club(int n,int c0_l,int c1_l,int c2_l,int left_people,int max_people){
	if(left_people == 0){
		//awa[c0_l][c1_l][c2_l][0][max_people] = n;
		return n;
	}
	if(c0_l == max_people){ //c0满员 
		if(c1_l == max_people){ //c1满员 
			//if(awa[c0_l][c1_l][c2_l][left_people][max_people] != 7834) return awa[c0_l][c1_l][c2_l][left_people][max_people];
			//awa[c0_l][c1_l][c2_l][left_people][max_people] = club(n+a[left_people][2],c0_l,c1_l,c2_l+1,left_people-1,max_people);
			return club(n+a[left_people][2],c0_l,c1_l,c2_l+1,left_people-1,max_people);
		}else{
			return max(club(n+a[left_people][1],c0_l,c1_l+1,c2_l,left_people-1,max_people),club(n+a[left_people][2],c0_l,c1_l,c2_l+1,left_people-1,max_people));
		}
	}
	if(c1_l == max_people){ //c0不满，c1满员 
		if(c2_l == max_people){ //c2满员 
			return club(n+a[left_people][0],c0_l+1,c1_l,c2_l,left_people-1,max_people);
		}else{
			return max(club(n+a[left_people][0],c0_l+1,c1_l,c2_l,left_people-1,max_people),club(n+a[left_people][2],c0_l,c1_l,c2_l+1,left_people-1,max_people));
		}
	}
	if(c2_l == max_people){ //c2满员，c0与c1均不满 
		return max(club(n+a[left_people][0],c0_l+1,c1_l,c2_l,left_people-1,max_people),club(n+a[left_people][1],c0_l,c1_l+1,c2_l,left_people-1,max_people));
	}
	//都不满 
	return max(max(club(n+a[left_people][0],c0_l+1,c1_l,c2_l,left_people-1,max_people),club(n+a[left_people][1],c0_l,c1_l+1,c2_l,left_people-1,max_people)),club(n+a[left_people][2],c0_l,c1_l,c2_l+1,left_people-1,max_people));
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		ans=0;max_people=n/2;
		vector<pair<int,int>> c0;
		vector<pair<int,int>> c2;
		vector<pair<int,int>> c1;
		for(int i=1;i<=n;i++){
			scanf("%d %d %d",&a[i][0],&a[i][1],&a[i][2]);
		}
		ans = club(0,0,0,0,n,max_people);
		//awa.clear()
		printf("%d\n",ans);
	}
	return 0;
} 
