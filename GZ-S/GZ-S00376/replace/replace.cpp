//GZ-S00376 肖家诺 安顺市第一高级中学 
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int n,q;
string s1[20005] ,s2[20005], qe1 , qe2 ;
bool comp1(string a,string b){
	return a.size()<b.size();
}

int repla(string q1,string q2){
	int num1,num2;int ans=0;
	for(num1=0;num1<q1.size();num1++)
		if(q1[num1]!=q2[num1])break;
	for(num2=q1.size()-1;num2>=0;num2--)
		if(q1[num2]!=q2[num2])break;
	int len=num2-num1+1;
	if(len==0)return 0;
	int it=1;
	for(it=0;it<=n;it++){
		int ac=s1[it].size(),j=0;
		for(int i=0;ac>=len-j-1;i++)
		{
			if(j==len){ans++;break;}
			if(s1[it][i]==q1[num1+j]&&s2[it][i]==q2[num1+j])j++;
			ac--;
		}
	}
	return ans;		
}

int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d %d",&n,&q);
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];	
	}
	
	sort(s1+1,s1+n+1,comp1);
	sort(s2+1,s2+n+1,comp1);
	
	for(int i=1;i<=q;i++){
		cin>>qe1>>qe2;
		cout<<repla(qe1,qe2)<<"\n";
	}
}
