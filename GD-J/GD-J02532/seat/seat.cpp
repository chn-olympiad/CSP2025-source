#include<bits/stdc++.h>
using namespace std;
vector<int> cj;
int ydp[105];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,rc;
	cin >> n >> m;
	for(int i=1;i<=n*m;i++){
		int t;
		cin >> t;
		cj.push_back(t);
	}
	rc=cj[0];
	sort(cj.begin(),cj.end(),cmp);
	int bm;
	for(int i=0;i<cj.size();i++){
		if(cj[i]==rc){
			bm=i+1;
			break;
		}
	}
	int c;
	if(bm%n!=0){
		c=bm/n+1;
	}else{
		c=bm/n;
	}
	ydp[1]=1;
	for(int i=2;i<=bm;i++){
		int tc;
		if(i%n!=0){
		tc=i/n+1;
		}else{
			tc=i/n;
		}
		if(i%n==1){
			ydp[i]=ydp[i-1];
		}else if(tc%2==0){
			ydp[i]=ydp[i-1]-1;
		}else if(tc%2==1){
			ydp[i]=ydp[i-1]+1;
		}
	}
	cout << c << ' ' << ydp[bm];
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
