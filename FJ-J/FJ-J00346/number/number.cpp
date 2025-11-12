#include<bits/stdc++.h>
using namespace std;
string s;
int b[1005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int u=s.size();
	for(int i=0;i<=u;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			b[0]++;
			b[b[0]]=s[i]-'0';
		}
	}
	for(int i=1;i<=b[0];i++){
		for(int j=1;j<i;j++){
			if(b[i]>b[j]){
				int y=b[i];
				b[i]=b[j];
				b[j]=y;
		}
	}
}
	for(int i=1;i<=b[0];i++){
		cout<<b[i];
	}

	fclose(stdin);
	fclose(stdout);

	
	return 0;
}
