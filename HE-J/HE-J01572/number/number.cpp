#include<bits/stdc++.h>//Ì«ºÃÀ±£¬ÎÒ¾ÓÈ»°ÑÓÅ»¯´ò³öÀ´ÁË¹þ¹þ¹þ¹þ¹þ¹þ¹þ¹þ¹þ¹þ¹þ¹þ¹þ¹þ¹þ¹þ¹þ¹þ¹þ¹þ¹þ¹þ¹þ¹þ¹þ¹þ¹þ¹þ¹þ¹þ¹þ¹þ¹þ¹þ¹þ¹þ¹þO(¡É_¡É)O~
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string st;
	cin>>st;
	int b[10]={};
//	int a[st.length()];
//	int temp=0;
//	for(int i=0;i<st.length();i++)
//	{
//		if(st[i]>='0'&&st[i]<='9')
//		{
//			a[temp]=st[i]-'0';
//			temp++;
//		}
//	}
//	sort(a,a+temp);			//¶¼¹ÖÄãº¦ÎÒ»¹ÐèÒªÓÅ»¯-_-|||ÔÙÓÃsortÎÒÊÇ¹·   //ÎÒ´ÓT2»ØÀ´ÁË£¬ÍôÍôÍô 
//	for(int i=temp-1;i>=0;i--)
//	{
//		cout<<a[i];
//	}
//	cout<<endl;
	for(int i=0;i<st.length();i++)
	{
		if(st[i]>='0'&&st[i]<='9')
		{
			b[st[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--)
	{
		for(int j=0;j<b[i];j++)
		{
			cout<<i;
		}
//		cout<<b[i];
	}
	cout<<endl;
	return 0;
}
