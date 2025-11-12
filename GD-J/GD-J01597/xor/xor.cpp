#include<bits/stdc++.h>
using namespace std;
int const N=5e5+5;
int n,k,cnt,ans;
int a[N];
bool isall1=true,isall01=true,c[N];

struct node{
	int x,y,l;
	bool operator<(const node&n)const{
		if(n.y==y){
			return n.l>l;
		}
		return n.y>y;
	}
}b[N];

bool check(int y1,int x2){
	if(x2<=y1){
		return true;
	}
	return false;
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			isall1=false;
			if(a[i]!=0){
				isall01=false;
			}
		}
	}
	
	if(isall1&&k==0){
		cout<<n/2;
		return 0;
	}
	
	if(isall01&&(k==0||k==1)){
		if(k==1){
			for(int i=1;i<=n;i++){
				if(a[i]==1){
					ans++;
				}
			}
			cout<<ans;
		}else{
			for(int i=1;i<=n;i++){
				if(a[i]==0){
					ans++;
				}
				if(a[i-1]==1&&a[i]==1&& !c[i-1]){
					c[i]=true;
					ans++;
				}
			}
			cout<<ans;
		}
		return 0;
	}
	
	//---------------------------------------------------------
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n-i+1;j++){
			int t=a[j];
			for(int g=j+1;g<=j+i-1;g++){
				t^=a[g];
			}
			if(t==k){
				b[cnt].x=j,b[cnt].y=j+i-1,b[cnt].l=i;
				cnt++;
			}
		}
	}
	sort(b,b+cnt);
//	for(int i=0;i<cnt;i++){
//		cout<<b[i].x<<" "<<b[i].y<<endl;
//	}
	int y1=0;
	for(int i=0;i<cnt;i++){
		if(!check(y1,b[i].x)){
			y1=b[i].y;
//			cout<<b[i].x<<' '<<b[i].y<<endl;
			ans++;
		}
	}
	cout<<ans;
	return 0;
} 
