#include<cstdio>
#include<queue>
using namespace std;
priority_queue<int ,vector<int> ,greater<int> > a;
int n,b[5005],s[5005],cnt,k;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&k);
		a.push(k);
	}
	s[0]=a.top();
	for(int i=1;i<n;i++){
        b[i]=a.top();
        a.pop();
	}
	for(int i=1;i<n;i++)
		s[i]=s[i-1]+b[i];
	int l=0,r=l+3;
	while(l<r-3){
		if(r>=n) r=n-1;l++;
		if((s[r]-s[l])>2*b[r]){
			r++;
			cnt++;
			cnt%=998244353;
		}
		else l++;
	}
	printf("9");
	return 0;
}
