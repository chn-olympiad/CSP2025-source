#include<bits/stdc++.h>
using namespace std;
const int N=2*1e5+5; 
long long n,m;//二元串数量和提出的串数 
struct ppp{
	string chu;
	string gai;
};
ppp p[N];
ppp ques[N];
long long gaii[N];
bool pan(string a,string b)
{//判断从a包含b么？ 
	if(a==b)
	{
		return true;
	}
	if(a.length()>=b.length()) return false;
	int num=a.length();
	for(int i=0;i<(b.length()-num);i++)
	{
		string qwe=b.substr(i,i+num);
		if(qwe==a) return 1;
	}
	return 0;
}
string fang(string a,string b,string ben)//ben为本来。取其中的a到b 
{
	int wa,wb;
	int num=a.length();
	for(int i=0;i<(b.length()-num);i++)
	{
		string qwe=b.substr(i,i+num);
		if(qwe==a) 
		{
			wa=i;
			wb=i+num;
		 } 
	}
string d=ben.substr(0,wa-1);
string e=ben.substr(wb+1,b.length()); 
string f=d+b;
f=f+e;
return f;
}
int main()
{
freopen("replace.in","r",stdin);
freopen("replace.out","w",stdout);
cin>>n>>m;
for(int i=0;i<n;i++)
{
	cin>>p[i].chu>>p[i].gai;
}
for(int i=0;i<m;i++)
{
	cin>>ques[i].chu>>ques[i].gai;	
}
for(int i=0;i<n;i++)
{
	for(int j=0;j<m;j++)
{
	if(pan(p[i].gai,ques[j].gai)&&pan(p[i].chu,ques[j].chu))
	{
		if(fang(p[i].chu,p[i].gai,ques[j].chu)==ques[j].gai){
			gaii[j]++;
		}
	 }
}
}

for(int i=0;i<m;i++)
{
	cout<<gaii[i]<<endl;
}
	return 0;
 } 
