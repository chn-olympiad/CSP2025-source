#include<bits/stdc++.h>
using namespace std;
int a[500000]={};
int a2[500000]={};
int a3[500000]={};
int n,k,ans=0;
struct a1_{
	int start;
	int end;
};

a1_ a1[500000]={};
bool cmp(a1_ a,a1_ b)
{if(a.start<b.start)
{return 1;
}
else if(a.start>b.start){
return 0;
}
else{
	return a.end<b.end;
}
//return a.start<b.start;

}
int yihuo(int a,int b)
{bitset<21> a1=a;
bitset<21> b1=b;
int c1=0;
for(int i=0;i<21;i++)
{if(a1[i]!=b1[i])
{c1+=pow(2,i);
}
}
return c1;
}
bool qujian(int start,int end)
{int jieguo=a[end];
if(end-start>=1&&(end!=0)){
	jieguo=yihuo(a[end],a2[end-1]);
	a3[end]=jieguo;
	}
a3[end]=jieguo;
	
if(jieguo==k)
{return 1;
}
else{return 0;
}
}
int main()
{	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	
	for(int i=0;i<n;i++){
	cin>>a[i];
	a2[i]=a[i];
	}
	
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n-i;j++){
			if(qujian(j,j+i)){
			a1[ans].start=j;
			a1[ans].end=j+i;
			ans+=1;
		}
		
	}
	for(int l=0;l<n;l++)
		{a2[l]=a3[l];
		}
}

	sort(a1,a1+ans,cmp);
	int ans1=1;
	
	int min1=a1[0].end;
	
	//cout<<min1;
	for(int i=1;i<ans;i++)
	{if(a1[i].start<=min1)
	{
	a1[i].start=0;
	a1[i].end=0;
	continue;
	}
	else{
		
		ans1+=1;
	min1=a1[i].end;
	}
	}
	//cout<<qujian(1,1);
	cout<<ans1;
return 0;
}
