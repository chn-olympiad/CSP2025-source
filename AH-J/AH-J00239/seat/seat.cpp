#include<bits/stdc++.h>
using namespace std;
int n,m,a[101],x;
bool cmp(int xx,int yy){
	return xx>=yy;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	x=a[1];
	int h,l=1,y=1;
	bool sx=0;
	sort(a+1,a+1+(n*m),cmp);
	for(int i=1;i<=n*m;i++){
		for(h=1;h>-1;h+=0){
			if(a[y]!=x){
				if(h!=n&&sx==0){
					h++;
					y+=1;
				}else if(h==n&&sx==0){
					l+=1;
					sx=1;
					y+=1;
				}else if(h!=1&&sx==1){
					h--;
					y+=1;
				}else if(h==n&&sx==1){
					h--;
					y+=1;
				}else if(h==1&&sx==1){
					l+=1;
					sx=0;
					y+=1;
				}else if(h==1&&sx==0){
					h++;
					y+=1;
				}
			}else{
				cout<<l<<" "<<h;
				return 0;
			}
		}
	}
	return 0;
}
