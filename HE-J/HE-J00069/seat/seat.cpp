#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b)
{
	return a>b;
}
int find(int grade[],int him){
	int i=0;
	while(grade[i]!=him)	{i++;
	}
	return i;
}
int n,m,ss;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>n>>m;
	ss=n*m;
	int grade[ss];
	cin>>grade[0];
	int him=grade[0];
	for(int i=1;i<ss;i++){
		cin>>grade[i];
		
	}
	sort(grade+0,grade+ss,cmp);
	/*for(int i=0;i<ss;i++){
		cout<<grade[i];
	}*/
	int xy=find(grade,him);
	int lie=xy/n+1;
	int hang=xy%n+1;
	cout<<lie<<' '<<hang;
	return 0;
}
