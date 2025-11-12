#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int t;int n;
int one=0,two=0,three=0;
struct guy{int num;ll a1;ll a2;ll a3;};
guy a[100005];
ll maxt=0;
bool youer=0,yousan=0;
void dfs(int,ll);

bool cmp1(guy m,guy n){return m.a1>n.a1;}

int main(){
	freopen("club.in","r",stdin);freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		for(int j=1;j<=n;j++){
			cin>>a[j].a1>>a[j].a2>>a[j].a3;
			if(a[j].a2!=0)youer=1;
			if(a[j].a3!=0)yousan=1;
		}


		if(n<=17){
			maxt=-1;one=0;two=0;three=0;
			dfs(1,0);
			
		}
		else if(youer){
			maxt=0;
			sort(a+1,a+n+1,cmp1);
			for(int j=1;j<=(n/2);j++){
				maxt+=a[i].a1;
			}
		}
		//fuck from here
		else if(yousan){
			maxt=0;one=0;two=0;
			sort(a+1,a+n+1,cmp1);
			for(int j=1;j<=n;j++){
				if(a[j].a1>=a[j].a2&&one<(n/2)){
					maxt+=a[j].a1;one++;
				}
				else{
					maxt+=a[j].a2;two++;
				}
			}
		}
		else{
			maxt=0;one=0;two=0;
			sort(a+1,a+n+1,cmp1);
			for(int j=1;j<=n;j++){
				if(a[j].a1>=a[j].a2&&a[j].a1>=a[j].a3&&one<(n/2)){
					maxt+=a[j].a1;one++;
				}
				else if(a[j].a2>=a[j].a1&&a[j].a2>=a[j].a3&&two<(n/2)){
					maxt+=a[j].a2;two++;
				}
				else{
					maxt+=a[j].a3;three++;
				}
			}
		}

		cout<<maxt<<endl;
		
	}
	return 0;
}

void dfs(int no,ll nowt){
	if(no==n+1){
		maxt=max(nowt,maxt);
		return;
	}
	if(one<n/2){
		one++;
		dfs(no+1,nowt+a[no].a1);
		one--;
	}
	if(two<n/2){
		two++;
		dfs(no+1,nowt+a[no].a2);
		two--;
	}
	if(three<n/2){
		three++;
		dfs(no+1,nowt+a[no].a3);
		three--;
	}
}
