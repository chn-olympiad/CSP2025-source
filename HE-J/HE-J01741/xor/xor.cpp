#include<bits/stdc++.h>
using namespace std;
struct ac{
	int x;
	int y;
}a[1000050];
int b[1000050];
int n,k,f,num=0;
bool cmp(ac s1,ac s2){
	return s1.y<s2.y;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>b[i];
	for(int i=1;i<=n;i++){
		int sum;
		for(int j=i;j<=n;j++){
			if(i==j) sum=b[i];
			else sum=sum^b[j];
			if(sum==k){
				num++;
				a[num].x=i;
				a[num].y=j;
			}
		}
	}
	sort(a+1,a+num+1,cmp);
	int ans=1;
	int xx=a[1].y;
	for(int i=2;i<=num;i++)
		if(a[i].x>xx) ans++,xx=a[i].y;
	cout<<ans;
	return 0;
}
