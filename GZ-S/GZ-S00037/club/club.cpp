#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);

	int t,n1,a,b,c,mmax=-1000000000,ans=0,ans1=0,ans2=0,cnt=0,cnt1=0,cnt2=0,cnt3=0,cnt4=0,cnt5=0,n2,n3,n4,n5,n6,n7,n8,n9,n10,n11,n12,n13,n14,n15,cnt6=0,cnt7=0,cnt8=0,cnt9=0,cnt10=0,cnt11=0,cnt12=0,cnt13=0,cnt14=0;

cin>>t;
	if(t==1)
	{
		cin>>n1;
		for(int i=1;i<=n1;i++)
		{
			
			cin>>a>>b>>c;
			if(a>b&&a>c)
			{
				mmax=a;
				ans++;
			}
			else if(b>a&&b>c)
			{
				mmax=b;
				ans1++;
			}
			else
			{
				mmax=c;
				ans2++;
			}
			if(ans>n1/2){
				mmax=ans-a+max(b,c);
			}
			if(ans1>n1/2){
				mmax=ans1-b+max(a,c);
			}
			if(ans2>n1/2){
				mmax=ans2-c+max(a,b);
			}
			cnt+=mmax;
		}
		cout<<cnt;
	}
	//t=2
	if(t==2)
	{
		cin>>n2;
		for(int i=1;i<=n2;i++)
		{
			cnt=0;
			cin>>a>>b>>c;
			if(a>b&&a>c)
			{
				mmax=a;
			}
			else if(b>a&&b>c)
			{
				mmax=b;
			}
			else
			{
				mmax=c;
			}
			cnt1+=mmax;
		}
		cin>>n3;
		for(int i=1;i<=n3;i++)
		{
			cnt=0;
			cin>>a>>b>>c;
			if(a>b&&a>c)
			{
				mmax=a;
			}
			else if(b>a&&b>c)
			{
				mmax=b;
			}
			else
			{
				mmax=c;
			}
			cnt2+=mmax;
		}
		cout<<cnt1<<endl;
		cout<<cnt2<<endl;
	}
	//t==3
	if(t==3)
	{
		cin>>n4;
		for(int i=1;i<=n4;i++)
		{
			//cnt3=0;
			cin>>a>>b>>c;
			if(a>b&&a>c)
			{
				mmax=a;
			}
			else if(b>a&&b>c)
			{
				mmax=b;
			}
			else
			{
				mmax=c;
			}
			cnt3+=mmax;
		}
		cin>>n5;
		for(int i=1;i<=n5;i++)
		{
			//cnt4=0;
			cin>>a>>b>>c;
			if(a>b&&a>c)
			{
				mmax=a;
				//cout<<"mmax="<<mmax<<endl;
			}
			else if(b>a&&b>c)
			{
				mmax=b;
				//cout<<"mmax="<<mmax<<endl;
			}
			else
			{
				mmax=c;
				//cout<<"mmax="<<mmax<<endl;
			}
			cnt4+=mmax;
			//cout<<"cnt4="<<cnt4<<endl;
		}

		cin>>n6;
		for(int i=1;i<=n6;i++)
		{
			//cnt5=0;
			cin>>a>>b>>c;
			if(a>b&&a>c)
			{
				mmax=a;
			}
			else if(b>a&&b>c)
			{
				mmax=b;
			}
			else
			{
				mmax=c;
			}
			cnt5+=mmax;
		}
		cout<<cnt3<<endl;
		cout<<cnt4<<endl;
		cout<<cnt5<<endl;
	}
	//t==4
	if(t==4)
	{
		cin>>n7;
		for(int i=1;i<=n7;i++)
		{
			//cnt3=0;
			cin>>a>>b>>c;
			if(a>b&&a>c)
			{
				mmax=a;
			}
			else if(b>a&&b>c)
			{
				mmax=b;
			}
			else
			{
				mmax=c;
			}
			cnt6+=mmax;
		}
		cin>>n8;
		for(int i=1;i<=n8;i++)
		{
			//cnt4=0;
			cin>>a>>b>>c;
			if(a>b&&a>c)
			{
				mmax=a;
				//cout<<"mmax="<<mmax<<endl;
			}
			else if(b>a&&b>c)
			{
				mmax=b;
				//cout<<"mmax="<<mmax<<endl;
			}
			else
			{
				mmax=c;
				//cout<<"mmax="<<mmax<<endl;
			}
			cnt7+=mmax;
			//cout<<"cnt4="<<cnt4<<endl;
		}

		cin>>n9;
		for(int i=1;i<=n9;i++)
		{
			//cnt5=0;
			cin>>a>>b>>c;
			if(a>b&&a>c)
			{
				mmax=a;
			}
			else if(b>a&&b>c)
			{
				mmax=b;
			}
			else
			{
				mmax=c;
			}
			cnt8+=mmax;
		}
		cin>>n10;
		for(int i=1;i<=n10;i++)
		{
			//cnt5=0;
			cin>>a>>b>>c;
			if(a>b&&a>c)
			{
				mmax=a;
			}
			else if(b>a&&b>c)
			{
				mmax=b;
			}
			else
			{
				mmax=c;
			}
			cnt9+=mmax;
		}
		cout<<cnt6<<endl;
		cout<<cnt7<<endl;
		cout<<cnt8<<endl;
		cout<<cnt9<<endl;
	}
	if(t==5)
	{
		cin>>n11;
		for(int i=1;i<=n11;i++)
		{
			//cnt3=0;
			cin>>a>>b>>c;
			if(a>b&&a>c)
			{
				mmax=a;
			}
			else if(b>a&&b>c)
			{
				mmax=b;
			}
			else
			{
				mmax=c;
			}
			cnt10+=mmax;
		}
		cin>>n12;
		for(int i=1;i<=n12;i++)
		{
			//cnt4=0;
			cin>>a>>b>>c;
			if(a>b&&a>c)
			{
				mmax=a;
				//cout<<"mmax="<<mmax<<endl;
			}
			else if(b>a&&b>c)
			{
				mmax=b;
				//cout<<"mmax="<<mmax<<endl;
			}
			else
			{
				mmax=c;
				//cout<<"mmax="<<mmax<<endl;
			}
			cnt11+=mmax;
			//cout<<"cnt4="<<cnt4<<endl;
		}

		cin>>n13;
		for(int i=1;i<=n13;i++)
		{
			//cnt5=0;
			cin>>a>>b>>c;
			if(a>b&&a>c)
			{
				mmax=a;
			}
			else if(b>a&&b>c)
			{
				mmax=b;
			}
			else
			{
				mmax=c;
			}
			cnt12+=mmax;
		}
		cin>>n14;
		for(int i=1;i<=n14;i++)
		{
			//cnt5=0;
			cin>>a>>b>>c;
			if(a>b&&a>c)
			{
				mmax=a;
			}
			else if(b>a&&b>c)
			{
				mmax=b;
			}
			else
			{
				mmax=c;
			}
			cnt13+=mmax;
		}
		cin>>n15;
		for(int i=1;i<=n15;i++)
		{
			//cnt5=0;
			cin>>a>>b>>c;
			if(a>b&&a>c)
			{
				mmax=a;
			}
			else if(b>a&&b>c)
			{
				mmax=b;
			}
			else
			{
				mmax=c;
			}
			cnt14+=mmax;
		}
		cout<<cnt10<<endl;
		cout<<cnt11<<endl;
		cout<<cnt12<<endl;
		cout<<cnt13<<endl;
		cout<<cnt14<<endl;
	}
	return 0;
}
	

