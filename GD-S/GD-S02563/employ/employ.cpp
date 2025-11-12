#include<bits/stdc++.h>
using namespace std;
bool visited[505];
int c[505];
int n,m,p;
int num=0;
string s;
void fun(int days){
	if(num==m){
		p++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(visited[i]==0){
//			cout<<num<<' ';
//			cout<<days<<' ';
			visited[i]=1;
			if(days<=c[i]){
				if(s[i]-'0'==1){
					num++;
					fun(days+1);
					num--;
				}else{
					fun(days+1);
				}
			}else{
				fun(days+1);
			}
			visited[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	sort(c+1,c+n+1);
//	for(int i=1;i<=n;i++){
//		cout<<c[i]<<' ';
//	}
//	cout<<endl;
	fun(0);
//	cout<<endl;
	cout<<p<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
