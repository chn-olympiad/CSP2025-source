#include<bits/stdc++.h>
using namespace std;
string st,stt;
int ans=-1,ans1;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>st;
	for(int i=0;st[i]=='a'||st[i]=='b'||st[i]=='c'||st[i]=='d'||st[i]=='e'||st[i]=='f'||st[i]=='g'||st[i]=='h'||st[i]=='i'||st[i]=='j'||st[i]=='k'||st[i]=='l'||st[i]=='m'||st[i]=='n'||st[i]=='o'||st[i]=='p'||st[i]=='q'||st[i]=='r'||st[i]=='s'||st[i]=='t'||st[i]=='u'||st[i]=='v'||st[i]=='w'||st[i]=='x'||st[i]=='y'||st[i]=='z'||st[i]=='1'||st[i]=='2'||st[i]=='3'||st[i]=='4'||st[i]=='5'||st[i]=='6'||st[i]=='7'||st[i]=='8'||st[i]=='9'||st[i]=='0';i++)
	{
		if(st[i]-'0'<=9&&st[i]-'0'>=0)
		{
			stt+=st[i];
		}
	}
	for(int i=0;stt[i]=='a'||stt[i]=='b'||stt[i]=='c'||stt[i]=='d'||stt[i]=='e'||stt[i]=='f'||stt[i]=='g'||stt[i]=='h'||stt[i]=='i'||stt[i]=='j'||stt[i]=='k'||stt[i]=='l'||stt[i]=='m'||stt[i]=='n'||stt[i]=='o'||stt[i]=='p'||stt[i]=='q'||stt[i]=='r'||stt[i]=='s'||stt[i]=='t'||stt[i]=='u'||stt[i]=='v'||stt[i]=='w'||stt[i]=='x'||stt[i]=='y'||stt[i]=='z'||stt[i]=='1'||stt[i]=='2'||stt[i]=='3'||stt[i]=='4'||stt[i]=='5'||stt[i]=='6'||stt[i]=='7'||stt[i]=='8'||stt[i]=='9'||stt[i]=='0';i++)
	{
		ans=-1;
		for(int j=i;stt[j]=='a'||stt[j]=='b'||stt[j]=='c'||stt[j]=='d'||stt[j]=='e'||stt[j]=='f'||stt[j]=='g'||stt[j]=='h'||stt[j]=='i'||stt[j]=='j'||stt[j]=='k'||stt[j]=='l'||stt[j]=='m'||stt[j]=='n'||stt[j]=='o'||stt[j]=='p'||stt[j]=='q'||stt[j]=='r'||stt[j]=='s'||stt[j]=='t'||stt[j]=='u'||stt[j]=='v'||stt[j]=='w'||stt[j]=='x'||stt[j]=='y'||stt[j]=='z'||stt[j]=='1'||stt[j]=='2'||stt[j]=='3'||stt[j]=='4'||stt[j]=='5'||stt[j]=='6'||stt[j]=='7'||stt[j]=='8'||stt[j]=='9'||stt[j]=='0';j++)
		{
			if(stt[j]-'0'>ans)
			{
				ans=stt[j]-'0';
				ans1=j;
			}
		}
		if(ans==0&&i==0)
		{
			cout<<0;
			return 0;
		}
		stt[ans1]=stt[i];
		stt[i]='0'+ans;
		cout<<ans;
	}
	fclose(stdin);
	fclose(stdout);
}
