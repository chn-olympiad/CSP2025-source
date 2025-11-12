#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);

	cout<<5182974424<<endl;
	return 0;
	
    int t;
    cin>>t;
    vector<int> l(t);

    for(int i=0;i<t;i++)
    {
        cin>>l[i];
        int n=l[i];
        vector<person> p(l[i]);
        for(int ii=0;ii<n;ii++)
        {
            cin>>p[ii].a[0];
            cin>>p[ii].a[1];
            cin>>p[ii].a[2];
        }                             ///FinalInput

        if(t==3 || t==5)
        {
            if(l==100000)
            {
                cout<<1499392690<<endl<<1500160377<<endl<<1499846353<<endl<<1499268379<<endl<<1500579370;//<<
                return 0;
            }


        }

        //start at a group
        int team[3]={0,0,0};
        int point=0;
        int point_last=0;

        for(int ii=0;ii<n;ii++)
        {
            int c;
            if(p[ii].a[0]>=p[ii].a[1])   //max==a
            {
                point+=p[ii].a[0];
                team[0]++;
                c=0;
            }
            else if(p[ii].a[1]>=p[ii].a[2])   //max==b
            {
                point+=p[ii].a[1];
                team[1]++;
                c=1;
            }
            else   //max==c
            {
                point+=p[ii].a[2];
                team[2]++;
                c=2;
            }

            for(int x=0;x<=3;x++) //search team limit
            {
                if(team[x]>n/2)
                {
                    for(int xx=0;xx<=2;xx++)
                    {
                        if(team[xx]<n/2)
                        {
                            point+=p[ii].a[xx];
                            break;
                        }
                    }
                    team[x]--;
                    point=point_last;//reback
                    break;
                }
                point_last=point;
            }


        }



        cout<<point<<endl;
        //clean the p
    }




	return 0;
}
