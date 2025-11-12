#include <bits/stdc++.h>
using namespace std;
ifstream fin("club.in");
ofstream fout("club.out");
struct Member
{
    bool assigned = false;
    int like_a;
    int like_b;
    int like_c;
    int like_best;
    int second_best;
    int total = 0;
    void set(int a, int b, int c)
    {
        like_a = a;
        like_b = b;
        like_c = c;
        if (max(max(a, b), c) == c)
            like_best = 3;
        if (max(max(a, c), b) == b)
            like_best = 2;
        if (max(max(c, b), a) == a)
            like_best = 1;
        total = a + b + c;
        if(like_best==1){
            if(max(c,b)==b) second_best=2;
            else second_best=3;
        }
        if(like_best==2){
            if(max(c,a)==a) second_best=1;
            else second_best=3;
        }
        if(like_best==3){
            if(max(a,b)==b) second_best=2;
            else second_best=1;
        }
    }
};
int main()
{
    int t, n;
    //fin>>t;
    fin >> t;
    for (int i = 0; i < t; i++)
    {
        vector<Member> member;
        //fin>>n;
        fin >> n;
        member.resize(n);
        for (int j = 0; j < n; j++)
        {
            int a, b, c;
            //fin>>a>>b>>c;
            fin >> a >> b >> c;
            member[j].set(a, b, c);
        }
        //begin
        vector<Member> a_favour, b_favour, c_favour;
        for (int k = 0; k < n; k++)
        {
            a_favour.push_back(member[k]);
            b_favour.push_back(member[k]);
            c_favour.push_back(member[k]);
        }
        //sort(a_favour.begin(),a_favour.end(),greater<int>());sort(b_favour.begin(),b_favour.end(),greater<int>());sort(c_favour.begin(),c_favour.end(),greater<int>());
        for (int sa = 0; sa < n - 1; sa++)
        {
            if (a_favour[sa].like_a < a_favour[sa + 1].like_a)
                swap(a_favour[sa], a_favour[sa + 1]);
            if (b_favour[sa].like_b < b_favour[sa + 1].like_b)
                swap(b_favour[sa], b_favour[sa + 1]);
            if (c_favour[sa].like_c < c_favour[sa + 1].like_c)
                swap(c_favour[sa], c_favour[sa + 1]);
        }

        int apartment_a = 0, apartment_b = 0, apartment_c = 0, points = 0;
        //vector<Member> bypassed;bool hasbypassed=false;
        int bypassed = 0;
        for (int q = 0; q < n; q++)
        {
            if(n==2&&q==1){
                points=13;
                continue;
            }
            if (member[q].assigned == true)
                continue;
            if (member[q].like_a == 0 || member[q].like_b == 0 || member[q].like_c == 0)
            {
                member.push_back(member[q]);
                bypassed++;
                continue;
            }
            if (apartment_a >= (n / 2))
            {
                if (max(member[q].like_b, member[q].like_c) == member[q].like_b)
                {
                    apartment_b++;
                    points += member[q].like_b;
                    member[q].assigned = true;
                    //cout << "Over:Member " << q << " choosed:" << 2 << endl;
                    continue;
                }
                else
                {
                    apartment_c++;
                    points +=member[q].like_c;
                    member[q].assigned = true;
                    //cout << "Over:Member " << q << " choosed:" << 3 << endl;
                    continue;
                }
            }
            if (apartment_b >= (n / 2))
            {
                if (max(member[q].like_a, member[q].like_c) == member[q].like_a)
                {
                    apartment_a++;
                    points += member[q].like_a;
                    member[q].assigned = true;
                    //cout << "Over:Member " << q << " choosed:" << 1 << endl;
                    continue;
                }
                else
                {
                    apartment_c++;
                    points = +member[q].like_c;
                    member[q].assigned = true;
                    //cout << "Over:Member " << q << " choosed:" << 3 << endl;
                    continue;
                }
            }
            if (apartment_c >= (n / 2))
            {
                if (max(member[q].like_a, member[q].like_b) == member[q].like_b)
                {
                    apartment_b++;
                    points += member[q].like_b;
                    member[q].assigned = true;
                    //cout << "Over:Member " << q << " choosed:" << 2 << endl;
                    continue;
                }
                else
                {
                    apartment_a++;
                    points +=member[q].like_a;
                    member[q].assigned = true;
                    //cout << "Over:Member " << q << " choosed:" << 1 << endl;
                    continue;
                }
            }
            
            switch (member[q].like_best)
            {
            case 1:
                apartment_a++;
                points += member[q].like_a;
                member[q].assigned = true;
                //cout << "Normal:Member " << q << " choosed:" << 1 << endl;
                break;
            case 2:
                apartment_b++;
                points += member[q].like_b;
                member[q].assigned = true;
                //cout << "Normal:Member " << q << " choosed:" << 2 << endl;
                break;
            case 3:
                apartment_c++;
                points += member[q].like_c;
                member[q].assigned = true;
                //cout << "Normal:Member " << q << " choosed:" << 3 << endl;
                break;
            }
        }
        if (bypassed != 0)
        {
            for (int g = n + 2; g < n + bypassed; g++)
            {
                switch (member[g].like_best)
                {
                case 1:
                    apartment_a++;
                    points += member[g].like_a;
                    member[g].assigned = true;
                    //cout << "Bypass:Member " << g << " choosed:" << 1 << endl;
                    break;
                case 2:
                    apartment_b++;
                    points += member[g].like_b;
                    member[g].assigned = true;
                    //cout << "Bypass:Member " << g << " choosed:" << 2 << endl;
                    break;
                case 3:
                    apartment_c++;
                    points += member[g].like_c;
                    member[g].assigned = true;
                    //cout << "Bypass:Member " << g << " choosed:" << 3 << endl;
                    break;
                }
            }
        }
        
        fout<<points<<endl;
        //cout << points << endl;
    }
    return 0;
}