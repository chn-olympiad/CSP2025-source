#include<bits/stdc++.h>
using namespace std;
int n,k;
int sum;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	srand(time(0));
	int ans=rand();
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		int x,y,z;
		cin>>x>>y>>z;
		sum+=z;
	}
	ans%=sum;
	cout<<ans;
	return 0;
}

//能A我吃1t huang_hym 
//能A我吃1t huang_hym 
//能A我吃1t huang_hym 
//能A我吃1t huang_hym 
//能A我吃1t huang_hym 
//能A我吃1t huang_hym 
//能A我吃1t huang_hym 
//能A我吃1t huang_hym 
//能A我吃1t huang_hym 
//能A我吃1t huang_hym 
//能A我吃1t huang_hym 
//能A我吃1t huang_hym 
//能A我吃1t huang_hym 

