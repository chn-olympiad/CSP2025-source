#include<bits/stdc++.h>
using namespace std;
int grade[105]={0};
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a,length;
	cin>>n>>m>>a;
	length=n*m-1;
	for(int i=0;i<length;i++){
		cin>>grade[i];
	}
	sort(grade,grade+length);
	reverse(grade,grade+length);
	for(int lie=1;lie<=m;lie++){
		for(int hang=1;hang<=n;hang++){
			int num=(lie-1)*n+hang;
			if(grade[num-1]<a){
				if(lie%2==1){
					cout<<lie<<' '<<hang;
					return 0;
				}
				else{
					if(hang==n)cout<<--lie<<' '<<n;
					else cout<<lie<<' '<<(n-hang+1);
					return 0;
				}
			}
		}
	}
}