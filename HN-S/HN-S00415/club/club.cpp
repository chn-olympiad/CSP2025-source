#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int sum(vector<int> a){
	int all = 0;
	for(int i=0;i<a.size();i++) all += a[i];
	return all;
}

bool cmp(int a,int b){  return a>b;  }

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int rounds;
	cin >> rounds;
	while(rounds--){
		
		//输入兼初始化 
		int n,ans=0;
		cin >> n;
		int biggest = n/2;
		vector < vector< vector<int> > > myxval( n+1,vector< vector<int> >(5,vector<int>(1,0) ) );//一维为新成员，二维为协会，三维为该协会分数 ,即myxval[i][j][k]为第i名新成员对j协会的好感值 
		for(int i=1;i<=n;i++){
			int a,b,c;
			cin >> a >> b >> c;
			myxval[i][0][0] = a;
			myxval[i][1][0] = b;
			myxval[i][2][0] = c;
			myxval[i][3][0] = max( max(a,b), max(b,c) );
			if(myxval[i][3][0] ==a) myxval[i][4][0] = max(b,c); 
			else if(myxval[i][3][0] ==b) myxval[i][4][0] = max(a,c); 
			else if(myxval[i][3][0] ==c) myxval[i][4][0] = max(a,b); 
		}
		vector<int> oneval,twoval,thrval; 
		int one,two,thr,maxs,onev,twov,thrv,oneth=0,twoth=0,thrth=0;
		for(int i = 1;i<=n;i++){
			int big = myxval[i][3][0];
			int bigth;
			if(big == myxval[i][0][0]) oneval.push_back(big);
			else if(big == myxval[i][1][0]) twoval.push_back(big);
			else if(big == myxval[i][2][0]) thrval.push_back(big);
		}
		sort(oneval.begin(),oneval.end(),cmp);
		sort(twoval.begin(),oneval.end(),cmp);
		sort(thrval.begin(),oneval.end(),cmp);
		one = sum(oneval);
		two = sum(twoval);
		thr = sum(thrval);
		maxs = max( max( sizeof(oneval),sizeof(twoval) ),max( sizeof(twoval),sizeof(thrval) ) );
		
		for(int i=0;i<maxs;i++){
			int maxv = -1;
			if(onev >= biggest&&twov <= biggest&&thrv<=biggest){
				maxv = max(twoval[twoth],thrval[thrth]);
				ans += maxv;
				if(twoval[twoth] == maxv){
					twoth++;
					twov += maxv;
				}else if(thrval[thrth] == maxv){
					thrth++;
					thrv += maxv;
				}
			}else if(two >= biggest&&onev <= biggest&&thrv<=biggest){
				maxv = max(oneval[twoth],thrval[thrth]);
				ans += maxv;
				if(oneval[oneth] == maxv){
					oneth++;
					onev += maxv;
				}else if(thrval[thrth] == maxv){
					thrth++;
					thrv += maxv;
				}
			}else if(thr >= biggest&&twov <= biggest&&onev<=biggest){
				maxv = max(twoval[twoth],oneval[oneth]);
				ans += maxv;
				if(twoval[twoth] == maxv){
					twoth++;
					twov += maxv;
				}else if(oneval[thrth] == maxv){
					oneth++;
					onev += maxv;
				}
			}else if(one >= biggest&&twov >= biggest&&thrv<=biggest){
				maxv = thrval[thrth];
				ans += maxv;
				thrv += maxv;
			}else if(one >= biggest&&thrv <= biggest&&twov<=biggest){
				maxv = twoval[twoth];
				ans += maxv;
				twov += maxv;
			}else if(two >= biggest&&thrv <= biggest&&onev<=biggest){
				maxv = oneval[thrth];
				ans += maxv;
				onev += maxv;
			}else{
				maxv = max( max(oneval[oneth],twoval[twoth]),max(twoval[twoth],thrval[thrth]) );
				ans+=maxv;
				if(oneval[oneth] == maxv){
					oneth++;
					onev += maxv;
				}else if(twoval[twoth] == maxv){
					twoth++;
					twov += maxv;
				}else if(thrval[thrth] == maxv){
					thrth++;
					thrv += maxv;
				}
			}
		} 
		cout << ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
