#include<bits/stdc++.h> 
using namespace std;
struct node{
	int x,id;
}a[505],b[1005];
int n,m,ans;
bool mp[505];
string s;
bool check(string x){
	int d[505]={},k=0;
	for(int i=0;i<m;i++){
		d[i]=a[x[i]-'0'].x;
	}
	int cnt=0;
	for(int i=0;i<n;i++){
		if(s[i]=='0'||d[i]==0){
			for(int j=i;j<n;j++){
				d[j]--;
			}
		}
		if(s[i]=='1'&&d[i]!=0){
			cnt++;
		}
	}
	return cnt>=m;
}
void find(string sum,int cnt){
	if(cnt>m){
		ans+=check(sum);
		ans%=998244353;
		cout<<sum<<"\n";
		return;
	}
	for(int i=1;i<=n;i++){
		if(mp[a[i].id]==0){
			mp[a[i].id]=1;
			find(sum+char(a[i].id+'0'),cnt+1);
			mp[a[i].id]=0;
		}
	}
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i].x;
		a[i].id=i;
	}
	for(int i=1;i<=n;i++){
		b[i].id=a[i].id;
		b[i*2].id=a[i].id;
		b[i].x=a[i].x;
		b[i*2].x=a[i].x;
	}
	find("",0);
	cout<<ans;
	return 0;
}
