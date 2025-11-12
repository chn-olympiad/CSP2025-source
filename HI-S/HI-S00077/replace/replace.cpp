#include<bits/stdc++.h>
using namespace std;
int n;
int q;
struct str2{
	vector<int> s1;
	vector<int> s2;
};
struct question{
	string t1,t2;
};
str2 GETS(str2 x){
	x.s1.push_back(getchar());
	x.s2.push_back(getchar());
	return x;
}
question GETS2(question x){
	x.t1.push_back(getchar());
	x.t2.push_back(getchar());
	return x;
}
vector<str2>str;
vector<question>qst;
bool ifBelong(vector<int> S1,vector<int> S2){//find s1 in s2
bool Z=1;
	int S=S2.size();
	int SS=S1.size();
	for(int i=0;i<S-SS;i++){
		for(int i1=i;i1<SS;i1++){
			if(S1[i1]!=S2[i])Z=0;
		}
	}
	return Z;
}
int ans=0;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	while(!str.empty())str.pop_back();
	while(!qst.empty())qst.pop_back();
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		str2 h;
		h=GETS(h);
		str.push_back(h);
	}
	for(int j=1;j<=q;j++){
		question h;
		h=GETS2(h);
		qst.push_back(h);
	}
	for(int i=1;i<=q;i++){
		if(ifBelong(qst[i].t1,str[i].s1)&&ifBelong(qst[i].t2,str[i].s2))ans++;
	}
	cout<<ans<<endl;
	return 0;
}

