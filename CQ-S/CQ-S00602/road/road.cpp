#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k;
struct dy{
	int u,v,m;
}a[1000006];
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	int sum=0;
	for(int i=1;i<=m;i++){
		cin>>a[i].u>>a[i].v>>a[i].m;
		sum+=a[i].m;
	}
	cout<<sum;
	// ly baoyouwo AC  ;
	// CCF i love you so let me ac please;
	// let us all get into NOIP;
	//then into shengxuan ;
	//then NOI;
	//then I can AKIOI;
	// and China will be top 1 on earth;
	// this is how we can become top 1 ;
	
}

/*
   #####
     #
     #
     #
     #
     #
     #
   #####

  ##    ##
##  #  #  ##
#    ##     #
 #         #
  ##     ##
    ## ##
      #
      
########
#
#
#
#
#
########

########
#
#
#
#
#
########

########
#
#
########
#
#
#
SO let me AC
*/

