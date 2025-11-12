#include<bits/stdc++.h>
using namespace std;
int n;
const int maxn = 1e5+5;
struct Node{
	int x,y;
};
bool cmp(Node a,Node b){
	if(a.x == b.x){
		return a.y < b.y;
	}
	return a.x > b.x;
}
int cnt = 0;
Node a[maxn],b[maxn],c[maxn];
int cc[maxn];
int sum = 0;
int numa = 0;
int numb = 0;
int numc = 0;
int m;
void loop(){
	int a1 ;
	int b1 ;
	int c1 ;
	for(int i = 1;i<n+1;i++){
		a1 = a[i-1].x-a[i].x;
		b1 = b[i-1].x-b[i].x;
		c1 = c[i-1].x-c[i].x;
		//cout<<a1<<' '<<b1<<" "<<c1<<" "<<numa<<" "<<numb<<" "<<numc<<endl;
			
		for(int k = 0;k<3;k++){
			for(int j = 0;j<sum;j++){
				if(a[i-1].y==cc[j]){
					a1 = -1e5-sum;
					a[i-1].x = 0;
				}
			}
			//cout<<a1<<' '<<b1<<" "<<c1<<" "<<numa<<" "<<numb<<" "<<numc<<endl;
			if(numa<m&&a1>=b1&&a1>=0&&a1>=b1){
			//	cout<<a[i-1].x<<" "<<a[i-1].y<<endl;
				cnt += a[i-1].x;
				a1 = -1e5-sum;
				cc[sum] = a[i-1].y;
				++sum;
				numa++;
			}
			for(int j = 0;j<sum;j++){
				if(b[i-1].y==cc[j]){
					b1 = -1e5-sum;
					b[i-1].x = 0;
				}
			}
			//cout<<a1<<' '<<b1<<" "<<c1<<" "<<numa<<" "<<numb<<" "<<numc<<endl;
			if(numb<m&&b1>=a1>0&&b1>=0&&b1>=c1){
			//	cout<<b[i-1].x<<" "<<b[i-1].y<<endl;
				cnt += b[i-1].x;
				b1 = -1e5-sum;
				cc[sum] = b[i-1].y;
				++sum;
				++numb;
			}
			for(int j = 0;j<sum;j++){
				if(c[i-1].y==cc[j]){
					c1 = -1e5-sum;
					c[i-1].x = 0;
				}
			}
			//cout<<a1<<' '<<b1<<" "<<c1<<" "<<numa<<" "<<numb<<" "<<numc<<endl;
			if(numc<m&&c1>=b1>0&&c1>=0&&c1>=a1){
				//cout<<c[i-1].x<<" "<<c[i-1].y<<endl;
				cnt += c[i-1].x;
				c1 = -1e5-sum;
				cc[sum] = c[i-1].y;
				++sum;
				numc++;
			}
			if(sum>=n){
				break;
			}
		}
//		for(int ii = 0;ii<sum;ii++){
//			cout<<cc[ii]<<' ';
//		}
//		cout<<endl;
		if(numa==numb&&numb==numc&&numc>=m){
			cout<<cnt<<endl;
			break;
		}
		if(sum>=n){
			cout<<cnt<<endl;
			break;
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		bool flag = 1;
		cin>>n;
		m = n / 2;
		cnt = 0;
		sum = 0;
		numa = 0;
		numb = 0;
		numc = 0;
		memset(cc,0,sizeof(cc));
		for(int i = 1;i<=n;i++){
			cin>>a[i].x>>b[i].x>>c[i].x;
			if(b[i].x!=0||c[i].x!=0){
				flag = 0;
			}
			a[i].y = i;
			b[i].y = i;
			c[i].y = i;
		}
		sort(a,a+n+1,cmp);
		if(flag){
			int ccc = 0;
			for(int i = 0;i<m;i++){
				ccc = ccc + a[i].x;
			}
			cout<<ccc<<endl;
		}else{
			sort(b,b+n+1,cmp);		
			sort(c,c+n+1,cmp);
			loop();
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
