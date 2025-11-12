#include<bits/stdc++.h>
using namespace std;
struct Node{
	int cl[3];
	int m[3];
}stu[100006];


int T;
int n,a[100006],b,c;

void addnew(int a,int b,int c,int i)
{
	stu[i].cl[0]=a,stu[i].cl[1]=b,stu[i].cl[2]=c;
	if(a>=b&&a>=c) 
	{
		stu[i].m[0]=0;
		if(b>=c) stu[i].m[1]=1,stu[i].m[2]=2;
		else stu[i].m[1]=2,stu[i].m[2]=1;
	}
	else if(b>=a&&b>=c) 
	{
		stu[i].m[0]=1;
		if(a>=c) stu[i].m[1]=0,stu[i].m[2]=2;
		else stu[i].m[1]=2,stu[i].m[2]=0;
	}
	else if(c>=a&&c>=b) 
	{
		stu[i].m[0]=2;
		if(a>=b) stu[i].m[1]=0,stu[i].m[2]=1;
		else stu[i].m[1]=1,stu[i].m[2]=0;
	}


	// for(int j=0;j<3;j++) cout<< stu[i].cl[j]<<"   "<<stu[i].m[j]<<endl;
	// 	cout<<endl;
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);


	scanf("%d",&T);
	for(int t=0,AAA=0;t<T;t++)
	{
		map<int,int> mp1;
		map<int,int> mp2;
		map<int,int> mp3;
		int cnt[3]={0,0,0};
		int zy[100006];
		memset(zy,0,sizeof zy);

		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			scanf("%d%d%d",&a[i],&b,&c);
			if(b==0&&c==0) AAA++;
			addnew(a[i],b,c,i);
		}
		if(AAA==n)
		{
			long long ans2=0;
			sort(a,a+n);
			for(int i=n-1;i>=n/2;i--) ans2+=a[i];
			printf("%lld\n",ans2);
			continue;

		}
		for(int i=0,h,w;i<n;i++)
		{
			if(stu[i].m[0]==0) mp1[stu[i].cl[0]]=i,cnt[0]++;
			else if(stu[i].m[0]==1) mp2[stu[i].cl[1]]=i,cnt[1]++;
			else mp3[stu[i].cl[2]]=i,cnt[2]++;


			if(cnt[0]>n/2) 
			{
				for(auto it:mp1) 
				{
					w=it.first,h=it.second;
					if(h!=-1000)break;
				}
				zy[h]++;
				mp1[w]=-1000;
				cnt[0]--;
				if(stu[h].m[zy[h]]==1) mp2[stu[h].cl[1]]=h,cnt[1]++;
				else mp3[stu[h].cl[2]]=h,cnt[2]++;
			}
			if(cnt[1]>n/2) 
			{
				for(auto it:mp2) 
				{
					w=it.first,h=it.second;
					if(h!=-1000)break;
				}
				zy[h]++;
				// cout<<zy[h]<<endl;
				mp2[w]=-1000;
				cnt[1]--;
				if(stu[h].m[zy[h]]==0) mp1[stu[h].cl[0]]=h,cnt[0]++;
				else mp3[stu[h].cl[2]]=h,cnt[2]++;
			}
			if(cnt[2]>n/2) 
			{
				for(auto it:mp3) 
				{
					w=it.first,h=it.second;
					if(h!=-1000)break;
				}
				zy[h]++;
				mp3[w]=-1000;
				cnt[2]--;
				if(stu[h].m[zy[h]]==0) mp1[stu[h].cl[0]]=h,cnt[0]++;
				else mp2[stu[h].cl[1]]=h,cnt[1]++;
			}
		}
		long long ans=0;



		// for(auto it:mp1) cout<<it.second<<" "<<it.first<<endl;
		// cout<<endl;
		// for(auto it:mp2) cout<<it.second<<" "<<it.first<<endl;
		// cout<<endl;
		// for(auto it:mp3) cout<<it.second<<" "<<it.first<<endl;




		for(auto it:mp1) if(it.second!=-1000) ans+=it.first;
		for(auto it:mp2) if(it.second!=-1000) ans+=it.first;
		for(auto it:mp3) if(it.second!=-1000) ans+=it.first;

		printf("%lld\n",ans);
	}
	return 0;
}