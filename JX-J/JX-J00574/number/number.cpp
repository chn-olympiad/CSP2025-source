include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin)
	freopen("number.out","w",stdout)
	int j=0;
	string s;
	cin>>s;
	string maxx='0';
	char a[1000000];
	for(int i=0;i<=s.size()-1;i++){
		if(maxx<=s[i]){
			maxx=s[i];
			a[j]=maxx;
			j++;
		}
	}for(int i=0;i<=s.size();i++){
		cout<<a[i];
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}	
