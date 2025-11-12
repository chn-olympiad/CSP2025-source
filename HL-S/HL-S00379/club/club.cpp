#include<bits/stdc++.h>
using namespace std;
int a[100001][3];
int b[100001][3];
int z[100001]={0};
struct ndd{
	int ans, r;
}s[3];
struct node{
	int id, a1, to;
}c[100001], d[100001], e[100001];
bool cmp(node x, node y){
	return x.a1>y.a1;
}
void suan1(int n){
	for(int i=1;i<=n;i++){
			if(z[i]==0 && s[c[i].to].r+1<=n/2){
				z[i]=1;
				s[c[i].to].ans+=c[i].a1;
				s[c[i].to].r++;
			}
		}
}
void suan2(int n){
	for(int i=1;i<=n;i++){
			if(z[i]==0 && s[d[i].to].r+1<=n/2){
				z[i]=1;
				s[d[i].to].ans+=d[i].a1;
				s[d[i].to].r++;
			}
		}
}
void suan3(int n){
	for(int i=1;i<=n;i++){
			if(z[i]==0 && s[e[i].to].r+1<=n/2){
				z[i]=1;
				s[e[i].to].ans+=e[i].a1;
				s[e[i].to].r++;
			}
		}
}
int maxn=-1;
void dasuan1(int n){
	suan1(n);
	suan2(n);
	suan3(n);
	int sum=0;
	sum+=s[1].ans;
	sum+=s[2].ans;
	sum+=s[3].ans;
	if(sum>maxn){
		maxn=sum;
	}
}
void dasuan2(int n){
	suan1(n);
	suan3(n);
	suan2(n);
	int sum=0;
	sum+=s[1].ans;
	sum+=s[2].ans;
	sum+=s[3].ans;
	if(sum>maxn){
		maxn=sum;
	}
}
void dasuan3(int n){
	suan3(n);
	suan1(n);
	suan2(n);
	int sum=0;
	sum+=s[1].ans;
	sum+=s[2].ans;
	sum+=s[3].ans;
	if(sum>maxn){
		maxn=sum;
	}
}
void dasuan4(int n){
	suan2(n);
	suan1(n);
	suan3(n);
	int sum=0;
	sum+=s[1].ans;
	sum+=s[2].ans;
	sum+=s[3].ans;
	if(sum>maxn){
		maxn=sum;
	}
}
void dasuan5(int n){
	suan2(n);
	suan3(n);
	suan1(n);
	int sum=0;
	sum+=s[1].ans;
	sum+=s[2].ans;
	sum+=s[3].ans;
	if(sum>maxn){
		maxn=sum;
	}
}
void dasuan6(int n){
	suan3(n);
	suan2(n);
	suan1(n);
	int sum=0;
	sum+=s[1].ans;
	sum+=s[2].ans;
	sum+=s[3].ans;
	if(sum>maxn){
		maxn=sum;
	}
}
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	for(int k=1;k<=t;k++){
		s[1].ans=0;
		s[1].r=0;
		s[2].ans=0;
		s[2].r=0;
		s[3].ans=0;
		s[3].r=0;
		maxn=-1;
		memset(z, 0, sizeof(z));
		int n;
		cin >> n; 
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				int x;
				scanf("%d", &x);
				a[i][j]=x;
			}
			b[i][1]=1;
			if(a[i][2]>a[i][1]){
				b[i][1]=2;
				b[i][2]=1;
				if(a[i][3]>a[i][2]){
					b[i][1]=3;
					b[i][2]=2;
					b[i][3]=1;
				}
				else{
					if(a[i][3]>a[i][1]){
						b[i][2]=3;
						b[i][3]=1;
					}
					else{
						b[i][3]=3;
					}
				}
			}
			else{
				b[i][2]=2;
				if(a[i][3]>a[i][1]){
					b[i][1]=3;
					b[i][2]=1;
					b[i][3]=2;
				}
				else{
					if(a[i][3]>a[i][2]){
						b[i][2]=3;
						b[i][3]=2;
					}
					else{
						b[i][3]=3;
					}
				}
			}
		} 
		for(int i=1;i<=n;i++){
			c[i].a1=a[i][b[i][1]];
			c[i].id=i;
			c[i].to=b[i][1];
			d[i].a1=a[i][b[i][2]];
			d[i].id=i;
			d[i].to=b[i][2];
			e[i].a1=a[i][b[i][3]];
			e[i].id=i;
			e[i].to=b[i][3];
		}
		sort(c+1, c+n+1, cmp);
		sort(d+1, d+n+1, cmp);
		sort(e+1, e+n+1, cmp);
		if(a[1][2]==0 && a[1][3]==0){
			for(int i=1;i<=n;i++){
			if(z[i]==0 && s[c[i].to].r+1<=n/2){
				z[i]=1;
				s[c[i].to].ans+=c[i].a1;
				s[c[i].to].r++;
			}
			}
			long long sum=0;
			sum+=s[1].ans;
			sum+=s[2].ans;
			sum+=s[3].ans;
			cout << sum << endl;
			return 0;
		}
		dasuan1(n);
		s[1].ans=0;
		s[1].r=0;
		s[2].ans=0;
		s[2].r=0;
		s[3].ans=0;
		s[3].r=0;
		memset(z, 0, sizeof(z));
		dasuan2(n);
		s[1].ans=0;
		s[1].r=0;
		s[2].ans=0;
		s[2].r=0;
		s[3].ans=0;
		s[3].r=0;
		memset(z, 0, sizeof(z));
		dasuan3(n);
		s[1].ans=0;
		s[1].r=0;
		s[2].ans=0;
		s[2].r=0;
		s[3].ans=0;
		s[3].r=0;
		memset(z, 0, sizeof(z));
		dasuan4(n);
		s[1].ans=0;
		s[1].r=0;
		s[2].ans=0;
		s[2].r=0;
		s[3].ans=0;
		s[3].r=0;
		memset(z, 0, sizeof(z));
		dasuan5(n);
		s[1].ans=0;
		s[1].r=0;
		s[2].ans=0;
		s[2].r=0;
		s[3].ans=0;
		s[3].r=0;
		memset(z, 0, sizeof(z));
		dasuan6(n);
		cout << maxn << endl;
	}
	return 0;
}
