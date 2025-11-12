#include <bits/stdc++.h>

using namespace std;

int t;

struct node
{
    int no1,no2,no3;
};

bool cmp(node n1,node n2)
{
    int mn1 = max(max(n1.no1,n1.no2),n1.no3);
    int mn2 = max(max(n2.no1,n2.no2),n2.no3);
    return mn1 > mn2;
}

bool cmpc1(node n1,node n2)
{
    return n1.no1 < n2.no1;
}

bool cmpc2(node n1,node n2)
{
    return n1.no2 < n2.no2;
}

bool cmpc3(node n1,node n2)
{
    return n1.no3 < n2.no3;
}

int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    //freopen("club1.in","r",stdin);
    //freopen("club1.out","w",stdout);
    cin >> t;
    while(t --)
    {
        int n;
        cin >> n;
        node a[n];
        bool flag = true;
        for (int i=0;i<n;i++)
        {
            cin >> a[i].no1 >> a[i].no2 >> a[i].no3;
            if (a[i].no2 != 0 && a[i].no3!= 0)
                flag = false;
        }
        if (flag)
        {
            priority_queue<int> pq;
            int sum = 0;
            for (auto i:a)
            {
                pq.push(i.no1);
            }
            for (int i=1;i<=n/2;i++)
            {
                sum += pq.top();
                pq.pop();
            }
            cout << sum;
            continue;
        }
        sort(a,a+n,cmp);
        int ans = 0;
        vector<node> c1,c2,c3;
        for (int i=0;i<n;i++)
        {
            sort(c1.begin(),c1.end(),cmpc1);
            sort(c2.begin(),c2.end(),cmpc2);
            sort(c3.begin(),c3.end(),cmpc3);
            int temp = max(max(a[i].no1,a[i].no2),a[i].no3);
            if (temp == a[i].no1 && c1.size()<n/2)
            {
                c1.push_back(a[i]);
                ans += temp;
                //cout << "c1.push_back(a[i]);ans += temp;" << endl;
            }
            else if (temp == a[i].no2 && c2.size()<n/2)
            {
                c2.push_back(a[i]);
                ans += temp;
                //cout << "c2.push_back(a[i]); ans += temp;" << endl;
            }
            else if (temp == a[i].no3 && c3.size()<n/2)
            {
                c3.push_back(a[i]);
                ans += temp;
                //cout << "c3.push_back(a[i]);ans += temp;" << endl;
            }
            else if (temp == a[i].no1 && c1.size() == n/2)
            {
                node tp = c1[0];
                int aa = max(tp.no2,tp.no3);
                int bb = max(a[i].no2,a[i].no3);
                if (((aa + a[i].no1)-(bb + tp.no1)) > 0)
                {
                    c1.erase(c1.begin());
                    ans += ((aa + a[i].no1)-(bb + tp.no1));
                    c1.push_back(a[i]);
                    //cout << "c1.erase(c1.begin());ans += ((aa + a[i].no1)-(bb + tp.no1));c1.push_back(a[i]);" << endl;
                    if (aa == tp.no2)
                    {
                        c2.push_back(tp);
                        //cout << "c2.push_back(tp); " << endl;
                    }
                    else
                    {
                        c3.push_back(tp);
                        //cout << "c3.push_back(tp); " << endl;
                    }
                }
                else
                {
                    if (bb == a[i].no2)
                    {
                        ans += bb;
                        c2.push_back(a[i]);
                        //cout << "ans += bb;c2.push_back(a[i]);" << endl;
                    }
                    else
                    {
                        ans += bb;
                        c3.push_back(a[i]);
                        //cout << "ans += bb;c3.push_back(a[i]);" << endl;
                    }
                }
            }
            else if (temp == a[i].no2 && c2.size() == n/2)
            {
                node tp = c2.front();
                int aa = max(tp.no1,tp.no3);
                int bb = max(a[i].no1,a[i].no3);
                if (((aa + a[i].no2)-(bb + tp.no2)) > 0)
                {
                    c2.erase(c2.begin());
                    ans += ((aa + a[i].no2)-(bb + tp.no2));
                    c2.push_back(a[i]);
                    //cout << "c2.erase(c2.begin());ans += ((aa + a[i].no2)-(bb + tp.no2));c2.push_back(a[i]);" << endl;
                    if (aa == tp.no1)
                    {
                        c1.push_back(tp);
                        //cout << "c1.push_back(tp);" << endl;
                    }
                    else
                    {
                        c3.push_back(tp);
                        //cout << "c3.push_back(tp);" << endl;
                    }
                }
                else
                {
                    if (bb == a[i].no1)
                    {
                        ans += bb;
                        c1.push_back(a[i]);
                        //cout << "ans += bb;c1.push_back(a[i]);" << endl;
                    }
                    else
                    {
                        ans += bb;
                        c3.push_back(a[i]);
                        //cout << "ans += bb;c3.push_back(a[i]);" << endl;
                    }
                }
            }
            else if (temp == a[i].no3 && c3.size() == n/2)
            {
                node tp = c3.front();
                int aa = max(tp.no1,tp.no2);
                int bb = max(a[i].no1,a[i].no2);
                if (((aa + a[i].no3)-(bb + tp.no3)) > 0)
                {
                    c3.erase(c3.begin());
                    ans += ((aa + a[i].no3)-(bb + tp.no3));
                    c3.push_back(a[i]);
                    //cout << "c3.erase(c3.begin()); ans += ((aa + a[i].no3)-(bb + tp.no3));c3.push_back(a[i]);" << endl;
                    if (aa == tp.no1)
                    {
                        c1.push_back(tp);
                        //cout << "c1.push_back(tp);" << endl;
                    }
                    else
                    {
                        c2.push_back(tp);
                        //cout << "c2.push_back(tp);" << endl;
                    }
                }
                else
                {
                    if (bb == a[i].no1)
                    {
                        ans += bb;
                        c1.push_back(a[i]);
                        //cout << "ans += bb;c1.push_back(a[i]);" << endl;
                    }
                    else
                    {
                        ans += bb;
                        c2.push_back(a[i]);
                        //cout << "ans += bb; c2.push_back(a[i]);" << endl;
                    }
                }
            }
        }
        cout << ans << endl;
        /*
        for (auto i:c1)
            cout << "c1:" << ' ' << i.no1 << ' ' << i.no2 << ' ' << i.no3 << endl;
        for (auto i:c2)
            cout << "c2:" << ' ' << i.no1 << ' ' << i.no2 << ' ' << i.no3 << endl;
        for (auto i:c3)
            cout << "c3:" << ' ' << i.no1 << ' ' << i.no2 << ' ' << i.no3 << endl;
        */
    }
    return 0;
}
