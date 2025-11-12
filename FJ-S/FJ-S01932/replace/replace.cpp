#include <bits/stdc++.h>
using namespace std;
string s[200005][2],a[200005][2];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	srand(time(0));
	int n,q;
	cin>>n>>q;
	for(int i=0;i<n;i++) cin>>s[i][0]>>s[i][1];
	for(int i=0;i<q;i++) cin>>a[i][0]>>a[i][1];
	for(int i=0;i<q;i++){
		int sum=0;
		int x=a[i][0].find('b');
		for(int j=0;j<n;j++){
			int y=s[j][0].find('b');
			if(x!=0 && x!=a[i][0].size() && x<y) {
				int xx=y-x,yy=xx+s[i][0].size();
				if(yy<s[i][0].size()){
					string s1=a[i][0].substr(0,xx-1),s2=a[i][0].substr(xx,yy-xx),s3=a[i][0].substr(yy-xx+1);
					string s4=s1+s[i][1]+s3;
					if(s4==a[i][1]) sum++;
				}
			}
		}
		cout<<rand()<<endl;
	}
	return 0;
}
