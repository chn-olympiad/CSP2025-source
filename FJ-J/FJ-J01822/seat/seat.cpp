#include<bits/stdc++.h>
using namespace std;
struct ls{
	int fs;
	bool bl;
}a[110],b[12][12];
int n,m,sm = -1,sn = -1;
bool cmp(ls aa,ls bb){
	return aa.fs > bb.fs;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a[1].fs;
	a[1].bl = 1;
	for(int i = 2;i <= n * m;i++){
		cin>>a[i].fs;
	}
	sort(a + 1,a + n *m + 2,cmp);
	bool hs = 1;
	int ss = 1,sss = 1;
	for(int i = 1;i <= m;i++){
		for(int j = 1;j <= n;j++){
			if(hs == 1){
				
				b[i][ss] = a[sss];
				if(a[sss].bl == 1){
					sn = i,sm = ss;
					break;
				}
				ss++;
			}else{
				ss--;
				b[i][ss] = a[sss];
				if(a[sss].bl == 1){
					sn = i,sm = ss;
					break;
				}
			}
			
			sss++;
		}
		if(hs == 1){
			hs = 0;
		}else{
			hs = 1;
		}
		if(sn != -1 && sm != -1){
			break;
		}
	}
	//for(int i = 1;i <= n + 1;i++){
	//	for(int j = 1;j <= m + 1;j++){
	//		cout<<b[i][j].fs<<" ";
	//	}
	//	cout<<endl;
	//}
	cout<<sn<<" "<<sm;
	return 0;
}
