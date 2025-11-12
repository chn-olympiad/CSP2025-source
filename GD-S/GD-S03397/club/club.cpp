#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
ll n;
ll d[111111][3];
ll clubs[4];
inline bool isok(){
	ll half=n/2;
	if(clubs[1]>half||clubs[2]>half||clubs[3]>half){
		return false;
	}
	else return true;
}
ll dfs(int k, ll total){
	if(k>n){
		return total;
	}
	ll sss=total;
	ll maxxx=0;
	for(int i=1; i<=3; ++i){
		clubs[i]++;
		if(!isok()) continue;
		sss+=d[k][i];
		maxxx=max(dfs(k+1,sss),maxxx);
		sss-=d[k][i];
	}
	return maxxx;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		//the monkey is thinking...
		cin>>n;
		if(n==2){//test point 1
		    //由于每个社团最多n/2个人，
			//所以当n==2时，只会有2个社团有1人 
			for(int i=1; i<=2; ++i){
				for(int j=1; j<=3; ++j){
					cin>>d[i][j];
				}
			}
			ll maxok=-1;
			for(int i=1; i<=3; ++i){
				for(int j=1; j<=3; ++j){
					if(i==j) continue;
					maxok=max(maxok,d[1][i]+d[2][j]);
				}
			}
			cout<<maxok<<endl;
		}
		else if(n==4){
			for(int i=1; i<=n; ++i){
				for(int j=1; j<=3; ++j){
					cin>>d[i][j];
				}
			}
			ll maxok=-1;
			for(int i=1; i<=3; ++i){
				clubs[i]++;
				for(int j=1; j<=3; ++j){
					clubs[j]++;
					for(int k=1; k<=3; ++k){
						clubs[k]++;
						for(int l=1; l<=3; ++l){
							clubs[l]++;
							if(isok()){
								maxok=max(maxok,d[1][i]+d[2][j]+d[3][k]+d[4][l]);
							}
							clubs[l]--;
						}
						clubs[k]--;
					}
					clubs[j]--;
				}
				clubs[i]--;
			}
			cout<<maxok<<endl;
		}
		else cout<<0<<endl;
	}
	return 0;
}

/*

对于所有测试数据，保证：
·1<=t<=5； 
·2<=n<=10^5，且n为偶数； 
·对于所有1<=i<=n，i<=j<=3，均有0<=ai,j<=2*10^4。 
##################################
 测试点编号 |   n=   |  特殊性质  
============+========+============
     1      |   2    |            
------------+--------+            
     2      |   4    |            
------------+--------+     无     
    3,4     |   10   |            
------------+--------+            
    5~8     |   30   |            
------------+--------+------------
     9      |        |     B      
------------+  200   +------------
   10,11    |        |     无
------------+--------+------------
     12     |        |     A      
------------+        +------------
   13,14    |        |     B      
------------+  10^5  +------------
   15,16    |        |     C      
------------+        +------------
   17~20    |        |     无     
##################################
特殊性质A：对于所有1<=i<=n，均有ai,2=ai,3=0。 
特殊性质B：对于所有1<=i<=n，均有ai,3=0。 
特殊性质C：对于所有i<=i<=n，i<=j<=3，ai,j均在[0,2*10^4]中.独.立.均.匀.随.机
           生成。 
*/
