//GZ-S00407 毕节梁才学校 詹桂鑫
#include<bits/stdc++.h>;

using namespace std;

int t,n;
int ans[10];

int main(){
	freopen("club1.in","r",stdin);
	freopen("club1.ans","w",stdout);
	freopen("club2.in","r",stdin);
	freopen("club2.ans","w",stdout);
	freopen("club3.in","r",stdin);
	freopen("club3.ans","w",stdout);
	freopen("club4.in","r",stdin);
	freopen("club4.ans","w",stdout);
	freopen("club5.in","r",stdin);
	freopen("club5.ans","w",stdout);
	cin>>t;
	for(int j=1;j<=t;j++){
		cin>>n;
		int mid=n/2;
		int la=0;
		int lb=0;
		int lc=0;
		for(int i=1;i<=n;i++){
			int a,b,c;
			int ma =-0x3f3f3f3f;
			cin>>a>>b>>c;
			ma=max(a,b);
			ma=max(ma,c);
			if(ma==a&&la<=mid){
				ans[j]+=a; 
				la++;
			}else if(ma==a&&la>mid){
				ans[j]+=max(b,c); 
				if(b>c){
					lb++;
				}else{
					lc++;
				}
			}if(ma==b&&lb<=mid){
				ans[j]+=b; 
				lb++;
			}else if(ma==b&&lb>mid){
				ans[j]+=max(a,c); 
				if(a>c){
					la++;
				}else{
					lc++;
				}
			}if(ma==c&&lc<=mid){
				ans[j]+=c; 
				lc++;
			}else if(ma==c&&lc>mid){
				ans[j]+=max(b,a); 
				if(b>a){
					lb++;
				}else{
					la++;
				}
			}
			
		}
	}
	for(int i=1;i<=t;i++){
		cout<<ans[i]<<endl;
	}
	return 0;
} 
