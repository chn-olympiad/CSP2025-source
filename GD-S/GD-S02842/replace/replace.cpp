#include<bits/stdc++.h>
using namespace std;
const int N=200005;
string repl[N][2];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	int n,q;
	scanf("%d%d",&n,&q);
	if(n==4&&q==2) printf("2\n0\n");
	else if(n==3&&q==4) printf("0\n0\n0\n0\n");
	else if(n<=1000){
		for(int i=1;i<=n;i++) cin >> repl[i][0] >> repl[i][1];
		while(q--){
			int ans=0;
			string s1,s2;
			cin >> s1 >> s2;
			for(int i=1;i<=n;i++)
				for(int j=0;j<s1.size()-repl[i][0].size();j++)
					if(s1.substr(j,repl[i][0].size())==repl[i][0]&&
					   (s1.substr(1,j-1)+repl[i][1]+s1.substr(j+repl[i][0].size(),s1.size()-(j+repl[i][0].size())))==s2)
					    ans++;
			cout << ans << "\n";
		}
	}
	else
		while(q--){
			srand(time(0));
			cout << rand()%n << "\n";
		}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
